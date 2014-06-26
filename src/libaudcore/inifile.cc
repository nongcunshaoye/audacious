/*
 * inifile.c
 * Copyright 2013 John Lindgren
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions, and the following disclaimer in the documentation
 *    provided with the distribution.
 *
 * This software is provided "as is" and without any warranty, express or
 * implied. In no event shall the authors be liable for any damages arising from
 * the use of this software.
 */

#include "inifile.h"

#include <string.h>
#include <glib.h>

#include "audstrings.h"
#include "vfs.h"

static char * strskip (char * str)
{
    while (g_ascii_isspace (* str))
        str ++;

    return str;
}

static char * strtrim (char * str)
{
    int len = strlen (str);

    while (len && g_ascii_isspace(str[len - 1]))
        str[-- len] = 0;

    return str;
}

EXPORT void inifile_parse (VFSFile * file,
 void (* handle_heading) (const char * heading, void * data),
 void (* handle_entry) (const char * key, const char * value, void * data),
 void * data)
{
    int size = 512;
    StringBuf buf (size);

    char * pos = buf;
    int len = 0;
    bool eof = false;

    while (1)
    {
        char * newline = (char *) memchr (pos, '\n', len);

        while (! newline && ! eof)
        {
            memmove (buf, pos, len);
            pos = buf;

            if (len >= size - 1)
            {
                size <<= 1;
                buf.resize (size);
                pos = buf;
            }

            len += vfs_fread (buf + len, 1, size - 1 - len, file);

            if (len < size - 1)
                eof = true;

            newline = (char *) memchr (pos, '\n', len);
        }

        if (newline)
            * newline = 0;
        else
            pos[len] = 0;

        char * start = strskip (pos);

        switch (* start)
        {
        case 0:
        case '#':
        case ';':
            break;

        case '[':
        {
            char * end = strchr (start + 1, ']');
            if (! end)
                break;

            * end = 0;
            handle_heading (strtrim (strskip (start + 1)), data);
            break;
        }

        default:
        {
            char * sep = strchr (start, '=');
            if (! sep)
                break;

            * sep = 0;
            handle_entry (strtrim (start), strtrim (strskip (sep + 1)), data);
            break;
        }
        }

        if (! newline)
            break;

        len -= newline + 1 - pos;
        pos = newline + 1;
    }
}

EXPORT bool inifile_write_heading (VFSFile * file, const char * heading)
{
    return (vfs_fputs (str_concat ({"\n[", heading, "]\n"}), file) >= 0);
}

EXPORT bool inifile_write_entry (VFSFile * file, const char * key, const char * value)
{
    return (vfs_fputs (str_concat ({key, "=", value, "\n"}), file) >= 0);
}
