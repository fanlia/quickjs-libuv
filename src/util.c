typedef struct qu_context_t {
  JSContext *ctx;
  JSValue func;
} qu_context_t;

static JSValue qu_result(JSContext *ctx, int status)
{
    if (status < 0) {
        return JS_ThrowPlainError(ctx, "%s: %s", uv_err_name(status), uv_strerror(status));
    }
    return JS_NewInt32(ctx, status);
}

static JSValue qu_run(JSContext *ctx, JSValue this_val, int argc, JSValue *argv)
{
    int res;
    res = uv_run(uv_default_loop(), UV_RUN_DEFAULT);
    return qu_result(ctx, res);
}
