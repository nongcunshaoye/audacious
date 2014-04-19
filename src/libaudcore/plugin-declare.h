/*
 * plugin-declare.h
 * Copyright 2014 John Lindgren
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

/* Required: AUD_PLUGIN_NAME */

#ifndef AUD_PLUGIN_DOMAIN
#define AUD_PLUGIN_DOMAIN PACKAGE
#endif
#ifndef AUD_PLUGIN_ABOUT
#define AUD_PLUGIN_ABOUT NULL
#endif
#ifndef AUD_PLUGIN_PREFS
#define AUD_PLUGIN_PREFS NULL
#endif
#ifndef AUD_PLUGIN_INIT
#define AUD_PLUGIN_INIT NULL
#endif
#ifndef AUD_PLUGIN_CLEANUP
#define AUD_PLUGIN_CLEANUP NULL
#endif
#ifndef AUD_PLUGIN_TAKE_MESSAGE
#define AUD_PLUGIN_TAKE_MESSAGE NULL
#endif
#ifndef AUD_PLUGIN_ABOUTWIN
#define AUD_PLUGIN_ABOUTWIN NULL
#endif
#ifndef AUD_PLUGIN_CONFIGWIN
#define AUD_PLUGIN_CONFIGWIN NULL
#endif

#ifdef AUD_DECLARE_TRANSPORT

/* Required: AUD_TRANSPORT_SCHEMES
 *           AUD_TRANSPORT_VTABLE */

AUD_TRANSPORT_PLUGIN (
    AUD_PLUGIN_NAME,
    AUD_PLUGIN_DOMAIN,
    AUD_PLUGIN_ABOUT,
    AUD_PLUGIN_PREFS,
    AUD_PLUGIN_INIT,
    AUD_PLUGIN_CLEANUP,
    AUD_PLUGIN_TAKE_MESSAGE,
    AUD_PLUGIN_ABOUTWIN,
    AUD_PLUGIN_CONFIGWIN,
    NULL,
    NULL,
    NULL,
    NULL,
    AUD_TRANSPORT_SCHEMES,
    AUD_TRANSPORT_VTABLE
)

#endif // AUD_DECLARE_TRANSPORT

#ifdef AUD_DECLARE_PLAYLIST

/* Required: AUD_PLAYLIST_EXTS
 *           AUD_PLAYLIST_LOAD */

#ifndef AUD_PLAYLIST_SAVE
#define AUD_PLAYLIST_SAVE NULL
#endif

AUD_PLAYLIST_PLUGIN (
    AUD_PLUGIN_NAME,
    AUD_PLUGIN_DOMAIN,
    AUD_PLUGIN_ABOUT,
    AUD_PLUGIN_PREFS,
    AUD_PLUGIN_INIT,
    AUD_PLUGIN_CLEANUP,
    AUD_PLUGIN_TAKE_MESSAGE,
    AUD_PLUGIN_ABOUTWIN,
    AUD_PLUGIN_CONFIGWIN,
    NULL,
    NULL,
    NULL,
    NULL,
    AUD_PLAYLIST_EXTS,
    AUD_PLAYLIST_LOAD,
    AUD_PLAYLIST_SAVE
)

#endif // AUD_DECLARE_PLAYLIST

#ifdef AUD_DECLARE_INPUT

#ifndef AUD_INPUT_SUBTUNES
#define AUD_INPUT_SUBTUNES FALSE
#endif
#ifndef AUD_INPUT_EXTS
#define AUD_INPUT_EXTS NULL
#endif
#ifndef AUD_INPUT_MIMES
#define AUD_INPUT_MIMES NULL
#endif
#ifndef AUD_INPUT_SCHEMES
#define AUD_INPUT_SCHEMES NULL
#endif
#ifndef AUD_INPUT_PRIORITY
#define AUD_INPUT_PRIORITY 0
#endif

/* Required: AUD_INPUT_IS_OUR_FILE
 *           AUD_INPUT_READ_TUPLE
 *           AUD_INPUT_PLAY */

#ifndef AUD_INPUT_WRITE_TUPLE
#define AUD_INPUT_WRITE_TUPLE NULL
#endif
#ifndef AUD_INPUT_READ_IMAGE
#define AUD_INPUT_READ_IMAGE NULL
#endif
#ifndef AUD_INPUT_INFOWIN
#define AUD_INPUT_INFOWIN NULL
#endif

AUD_INPUT_PLUGIN (
    AUD_PLUGIN_NAME,
    AUD_PLUGIN_DOMAIN,
    AUD_PLUGIN_ABOUT,
    AUD_PLUGIN_PREFS,
    AUD_PLUGIN_INIT,
    AUD_PLUGIN_CLEANUP,
    AUD_PLUGIN_TAKE_MESSAGE,
    AUD_PLUGIN_ABOUTWIN,
    AUD_PLUGIN_CONFIGWIN,
    NULL,
    NULL,
    NULL,
    NULL,
    AUD_INPUT_SUBTUNES,
    AUD_INPUT_EXTS,
    AUD_INPUT_MIMES,
    AUD_INPUT_SCHEMES,
    AUD_INPUT_PRIORITY,
    AUD_INPUT_IS_OUR_FILE,
    AUD_INPUT_READ_TUPLE,
    AUD_INPUT_PLAY,
    AUD_INPUT_WRITE_TUPLE,
    AUD_INPUT_READ_IMAGE,
    AUD_INPUT_INFOWIN
)

#endif // AUD_DECLARE_INPUT

#ifdef AUD_DECLARE_OUTPUT

#ifndef AUD_OUTPUT_PRIORITY
#define AUD_OUTPUT_PRIORITY 0
#endif
#ifndef AUD_OUTPUT_GET_VOLUME
#define AUD_OUTPUT_GET_VOLUME NULL
#endif
#ifndef AUD_OUTPUT_SET_VOLUME
#define AUD_OUTPUT_SET_VOLUME NULL
#endif

/* Required: AUD_OUTPUT_OPEN
 *           AUD_OUTPUT_CLOSE
 *           AUD_OUTPUT_GET_FREE
 *           AUD_OUTPUT_WAIT_FREE
 *           AUD_OUTPUT_WRITE
 *           AUD_OUTPUT_DRAIN
 *           AUD_OUTPUT_GET_TIME
 *           AUD_OUTPUT_PAUSE
 *           AUD_OUTPUT_FLUSH */

#ifndef AUD_OUTPUT_REOPEN
#define AUD_OUTPUT_REOPEN FALSE
#endif

AUD_OUTPUT_PLUGIN (
    AUD_PLUGIN_NAME,
    AUD_PLUGIN_DOMAIN,
    AUD_PLUGIN_ABOUT,
    AUD_PLUGIN_PREFS,
    AUD_PLUGIN_INIT,
    AUD_PLUGIN_CLEANUP,
    AUD_PLUGIN_TAKE_MESSAGE,
    AUD_PLUGIN_ABOUTWIN,
    AUD_PLUGIN_CONFIGWIN,
    NULL,
    NULL,
    NULL,
    NULL,
    AUD_OUTPUT_PRIORITY,
    AUD_OUTPUT_GET_VOLUME,
    AUD_OUTPUT_SET_VOLUME,
    AUD_OUTPUT_OPEN,
    AUD_OUTPUT_CLOSE,
    AUD_OUTPUT_GET_FREE,
    AUD_OUTPUT_WAIT_FREE,
    AUD_OUTPUT_WRITE,
    AUD_OUTPUT_DRAIN,
    AUD_OUTPUT_GET_TIME,
    AUD_OUTPUT_PAUSE,
    AUD_OUTPUT_FLUSH,
    AUD_OUTPUT_REOPEN
)

#endif // AUD_DECLARE_OUTPUT
