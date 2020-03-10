#include <napi.h>

#include "src/cpp/QMediaContent/qmediacontent_wrap.h"
#include "src/cpp/QMediaPlayer/qmediaplayer_wrap.h"

Napi::Object Main(Napi::Env env, Napi::Object exports) {
  QMediaContentWrap::init(env, exports);
  QMediaPlayerWrap::init(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)
