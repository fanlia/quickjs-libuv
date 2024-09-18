#include <uv.h>
#include <quickjs.h>
#define countof(x) (sizeof(x) / sizeof((x)[0]))

#include "version.c"

static const JSCFunctionListEntry qu_funcs[] = {
    JS_CFUNC_DEF("version", 0, qu_version ),
    JS_CFUNC_DEF("version_string", 0, qu_version_string ),
};

static int qu_init(JSContext *ctx, JSModuleDef *m)
{
    return JS_SetModuleExportList(ctx, m, qu_funcs, countof(qu_funcs));
}

JSModuleDef *js_init_module(JSContext *ctx, const char *module_name)
{
    JSModuleDef *m;
    m = JS_NewCModule(ctx, module_name, qu_init);
    if (!m)
        return NULL;
    JS_AddModuleExportList(ctx, m, qu_funcs, countof(qu_funcs));
    return m;
}
