
int64_t counter = 0;

void wait_for_a_while(uv_idle_t* handle) {
    counter++;

    if (counter >= 10e6) {
        uv_idle_stop(handle);
    }
}

uv_idle_t idler;

static JSValue qu_idle_test(JSContext *ctx, JSValue this_val, int argc, JSValue *argv)
{

    uv_idle_init(uv_default_loop(), &idler);
    uv_idle_start(&idler, wait_for_a_while);

    return JS_UNDEFINED;
}
