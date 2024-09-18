#include <uv.h>
#include <quickjs.h>
#define countof(x) (sizeof(x) / sizeof((x)[0]))

static JSValue qu_version(JSContext *ctx, JSValue this_val, int argc, JSValue *argv)
{
    unsigned int res;
    res = uv_version();
    return JS_NewUint32(ctx, res);
}

static JSValue qu_version_string(JSContext *ctx, JSValue this_val, int argc, JSValue *argv)
{
    const char *res;
    res = uv_version_string();
    return JS_NewString(ctx, res);
}

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
