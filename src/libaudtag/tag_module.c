#include <glib.h>
#include <libaudcore/tuple.h>
#include <libaudcore/vfs.h>
#include "tag_module.h"
#include "wma/module.h"
#include "util.h"

void init_tag_modules(void) {
    char key[10] = "wma";
    tag_modules = mowgli_dictionary_create(strcasecmp);
    mowgli_dictionary_add(tag_modules, key, &wma);

}

tag_module_t *find_tag_module(VFSFile * fd) {
    char key[10] = "wma";
    tag_module_t *mod = (tag_module_t*) mowgli_dictionary_retrieve(tag_modules, key);
    if (mod->can_handle(fd))
        return mod;
    DEBUG("no module found\n");
    return NULL;
}
