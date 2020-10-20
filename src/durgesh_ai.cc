// Copyright 2020 Alpha Cephei Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "durgesh_ai.h"
#include "kaldi_recognizer.h"
#include "model.h"
#include "spk_model.h"

#include <string.h>

using namespace kaldi;

DurgeshAIModel *durgesh_ai_model_new(const char *model_path)
{
    return (DurgeshAIModel *)new Model(model_path);
}

void durgesh_ai_model_free(DurgeshAIModel *model)
{
    ((Model *)model)->Unref();
}

DurgeshAISpkModel *durgesh_ai_spk_model_new(const char *model_path)
{
    return (DurgeshAISpkModel *)new SpkModel(model_path);
}

void durgesh_ai_spk_model_free(DurgeshAISpkModel *model)
{
    ((SpkModel *)model)->Unref();
}

DurgeshAIRecognizer *durgesh_ai_recognizer_new(DurgeshAIModel *model, float sample_rate)
{
    return (DurgeshAIRecognizer *)new KaldiRecognizer((Model *)model, sample_rate);
}

DurgeshAIRecognizer *durgesh_ai_recognizer_new_spk(DurgeshAIModel *model, DurgeshAISpkModel *spk_model, float sample_rate)
{
    return (DurgeshAIRecognizer *)new KaldiRecognizer((Model *)model, (SpkModel *)spk_model, sample_rate);
}

DurgeshAIRecognizer *durgesh_ai_recognizer_new_grm(DurgeshAIModel *model, float sample_rate, const char *grammar)
{
    return (DurgeshAIRecognizer *)new KaldiRecognizer((Model *)model, sample_rate, grammar);
}

int durgesh_ai_recognizer_accept_waveform(DurgeshAIRecognizer *recognizer, const char *data, int length)
{
    return ((KaldiRecognizer *)(recognizer))->AcceptWaveform(data, length);
}

int durgesh_ai_recognizer_accept_waveform_s(DurgeshAIRecognizer *recognizer, const short *data, int length)
{
    return ((KaldiRecognizer *)(recognizer))->AcceptWaveform(data, length);
}

int durgesh_ai_recognizer_accept_waveform_f(DurgeshAIRecognizer *recognizer, const float *data, int length)
{
    return ((KaldiRecognizer *)(recognizer))->AcceptWaveform(data, length);
}

const char *durgesh_ai_recognizer_result(DurgeshAIRecognizer *recognizer)
{
    return ((KaldiRecognizer *)recognizer)->Result();
}

const char *durgesh_ai_recognizer_partial_result(DurgeshAIRecognizer *recognizer)
{
    return ((KaldiRecognizer *)recognizer)->PartialResult();
}

const char *durgesh_ai_recognizer_final_result(DurgeshAIRecognizer *recognizer)
{
    return ((KaldiRecognizer *)recognizer)->FinalResult();
}

void durgesh_ai_recognizer_free(DurgeshAIRecognizer *recognizer)
{
    delete (KaldiRecognizer *)(recognizer);
}

void durgesh_ai_set_log_level(int log_level)
{
    SetVerboseLevel(log_level);
}
