#include <jni.h>
#include <stdio.h>

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLInputConnection_nativeSetComposingText(JNIEnv *env,
                                                                           jobject instance,
                                                                           jstring text_,
                                                                           jint newCursorPosition) {
    const char *text = (*env)->GetStringUTFChars(env, text_, 0);

    // TODO

    (*env)->ReleaseStringUTFChars(env, text_, text);
}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLInputConnection_nativeCommitText(JNIEnv *env, jobject instance,
                                                                     jstring text_,
                                                                     jint newCursorPosition) {
    const char *text = (*env)->GetStringUTFChars(env, text_, 0);

    // TODO

    (*env)->ReleaseStringUTFChars(env, text_, text);
}

JNIEXPORT jstring JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_nativeGetHint(JNIEnv *env, jclass type,
                                                           jstring name_) {
    const char *name = (*env)->GetStringUTFChars(env, name_, 0);

    // TODO

    (*env)->ReleaseStringUTFChars(env, name_, name);

    return (*env)->NewStringUTF(env, "");
}

JNIEXPORT jint JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_nativeRemoveJoystick(JNIEnv *env, jclass type,
                                                                  jint device_id) {

    // TODO

}

JNIEXPORT jint JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_nativeAddJoystick(JNIEnv *env, jclass type,
                                                               jint device_id, jstring name_,
                                                               jint is_accelerometer, jint nbuttons,
                                                               jint naxes, jint nhats,
                                                               jint nballs) {
    const char *name = (*env)->GetStringUTFChars(env, name_, 0);

    // TODO

    (*env)->ReleaseStringUTFChars(env, name_, name);
}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativeSurfaceDestroyed(JNIEnv *env, jclass type) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativeSurfaceChanged(JNIEnv *env, jclass type) {
    printf("JNI - Surface changed\n");
}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativeAccel(JNIEnv *env, jclass type, jfloat x,
                                                           jfloat y, jfloat z) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativeTouch(JNIEnv *env, jclass type,
                                                           jint touchDevId, jint pointerFingerId,
                                                           jint action, jfloat x, jfloat y,
                                                           jfloat p) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativeMouse(JNIEnv *env, jclass type, jint button,
                                                           jint action, jfloat x, jfloat y) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativeKeyboardFocusLost(JNIEnv *env, jclass type) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativeKeyUp(JNIEnv *env, jclass type, jint keycode) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativeKeyDown(JNIEnv *env, jclass type,
                                                             jint keycode) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativeHat(JNIEnv *env, jclass type, jint device_id,
                                                         jint hat_id, jint x, jint y) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativeJoy(JNIEnv *env, jclass type, jint device_id,
                                                         jint axis, jfloat value) {

    // TODO

}

JNIEXPORT jint JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativePadUp(JNIEnv *env, jclass type, jint device_id,
                                                           jint keycode) {

    // TODO

}

JNIEXPORT jint JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativePadDown(JNIEnv *env, jclass type,
                                                             jint device_id, jint keycode) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativeResize(JNIEnv *env, jclass type, jint x,
                                                            jint y, jint format, jfloat rate) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_onNativeDropFile(JNIEnv *env, jclass type,
                                                              jstring filename_) {
    const char *filename = (*env)->GetStringUTFChars(env, filename_, 0);

    // TODO

    (*env)->ReleaseStringUTFChars(env, filename_, filename);
}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_nativeResume(JNIEnv *env, jclass type) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_nativePause(JNIEnv *env, jclass type) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_nativeQuit(JNIEnv *env, jclass type) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_nativeLowMemory(JNIEnv *env, jclass type) {

    // TODO

}

JNIEXPORT jint JNICALL
Java_com_example_edfil_conceptv2_SDLActivity_nativeInit(JNIEnv *env, jclass type,
                                                        jobject arguments) {

    // TODO

}