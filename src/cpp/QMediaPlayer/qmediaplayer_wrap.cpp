#include "qmediaplayer_wrap.h"

#include <napi.h>

#include <QMediaPlayer>
#include <QUrl>

#include "nodegui/Extras/Utils/nutils.h"
#include "nodegui/QtCore/QObject/qobject_macro.h"
#include "nodegui/QtCore/QUrl/qurl_wrap.h"

Napi::FunctionReference QMediaPlayerWrap::constructor;

Napi::Object QMediaPlayerWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QMediaPlayer";
  Napi::Function func =
      DefineClass(env, CLASSNAME,
                  {InstanceMethod("play", &QMediaPlayerWrap::play),
                   InstanceMethod("setMedia", &QMediaPlayerWrap::setMedia),
                   QOBJECT_WRAPPED_METHODS_EXPORT_DEFINE(QMediaPlayerWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QMediaPlayerWrap::QMediaPlayerWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QMediaPlayerWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 0) {
    this->instance = new NMediaPlayer();
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureQObject(this->getInternalInstance());
}

QMediaPlayerWrap::~QMediaPlayerWrap() { this->instance; }

NMediaPlayer* QMediaPlayerWrap::getInternalInstance() { return this->instance; }

Napi::Value QMediaPlayerWrap::play(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  this->instance->play();
  return env.Undefined();
}

Napi::Value QMediaPlayerWrap::setMedia(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  if (info.Length() == 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  auto napiObj = info[0].As<Napi::Object>().Get("native").As<Napi::Object>();
  auto qUrlWrap = Napi::ObjectWrap<QUrlWrap>::Unwrap(napiObj);
  this->instance->setMedia(*qUrlWrap->getInternalInstance());
  return env.Undefined();
}
