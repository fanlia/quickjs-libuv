
int64_t counter = 0;

void wait_for_a_while(uv_idle_t* handle) {
    qu_context_t* data = (qu_context_t*)handle->data;
    counter++;

    if (counter >= 10e5) {
        JS_Call(data->ctx, data->func, JS_UNDEFINED, 0, NULL);
        uv_idle_stop(handle);
    }
}

uv_idle_t idler;
qu_context_t qc;

static JSValue qu_idle_test(JSContext *ctx, JSValue this_val, int argc, JSValue *argv)
{
    JSValue func;
    func = argv[0];
    if (!JS_IsFunction(ctx, func))
        return JS_ThrowTypeError(ctx, "not a function");

    uv_idle_init(uv_default_loop(), &idler);
    qc.ctx = ctx;
    qc.func = JS_DupValue(ctx, func);
    idler.data = &qc;

    uv_idle_start(&idler, wait_for_a_while);

    return JS_UNDEFINED;
}
