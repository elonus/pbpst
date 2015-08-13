#pragma once

#include "main.h"
#include <linux/limits.h>
#include <libgen.h>

static const char swp_db_err [] =
    "pbpst: Could not create the swap db: %s\n"
    "pbpst: Ensure no other instances of pbpst are running and that all pastes"
    " have been saved\npbpst: Then manually remove: %s/%s\n";

#define DEF_DB() json_pack("{s:s,s:{}}", "default_provider",\
                           "https://ptpb.pw", "pastes")

char *
db_locate (const struct pbpst_state *);

signed
db_swp_init (const char *);

signed
db_swp_cleanup (const char *, signed);

json_t *
db_read (const struct pbpst_state *, const char *);

// vim: set ts=4 sw=4 et: