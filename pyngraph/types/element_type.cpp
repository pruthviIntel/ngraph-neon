// ----------------------------------------------------------------------------
// Copyright 2017 Nervana Systems Inc.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// ----------------------------------------------------------------------------

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "ngraph/types/element_type.hpp"
#include "pyngraph/types/element_type.hpp"
#include "ngraph/ops/parameter.hpp"

namespace py = pybind11;

void regclass_pyngraph_Type(py::module m){
    py::class_<ngraph::element::Type, std::shared_ptr<ngraph::element::Type>> type(m, "Type");
    type.attr("boolean") = ngraph::element::boolean;
    type.attr("f32")     = ngraph::element::f32;
    type.attr("f64")     = ngraph::element::f64;
    type.attr("i8")      = ngraph::element::i8;
    type.attr("i16")     = ngraph::element::i16;
    type.attr("i32")     = ngraph::element::i32;
    type.attr("i64")     = ngraph::element::i64;
    type.attr("u8")      = ngraph::element::u8;
    type.attr("u16")     = ngraph::element::u16;
    type.attr("u32")     = ngraph::element::u32;
    type.attr("u64")     = ngraph::element::u64;
}
