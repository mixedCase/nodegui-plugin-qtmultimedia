#pragma once
#include <napi.h>

#include <QStringList>

inline Napi::Array mapQStringListToNapiArray(const Napi::Env& env,
                                             const QStringList& qsl) {
  uint32_t qslLength = qsl.size();
  Napi::Array napiArray = Napi::Array::New(env, qslLength);
  for (uint32_t i = 0; i < qslLength; i++) {
    std::string stdStr = qsl.at(i).toStdString();
    napiArray.Set(i, Napi::String::New(env, stdStr));
  }
  return napiArray;
}