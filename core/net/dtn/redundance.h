#ifndef __STORAGE_H__
#define __STORAGE_H__

#include <stdlib.h>
#include <stdio.h>
#include "net/dtn/bundle.h"
struct redundance_check {
	char *name;

	void (* init)(void);
	void (* reinit)(void);
	uint8_t (* check)(struct bundle_t *bundle);
	uint8_t (* set)(struct bundle_t *bundle);
};

extern const struct redundance_check REDUNDANCE;
#endif