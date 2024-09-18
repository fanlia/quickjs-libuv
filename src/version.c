
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
