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
//#include <string>
#include "ngraph/common.hpp"
#include "ngraph/ops/one_hot.hpp" // ngraph::op::OneHot
#include "pyngraph/ops/one_hot.hpp"

namespace py = pybind11;

void regclass_pyngraph_op_OneHot(py::module m) {

    //py::module::import("wrapper.ngraph.ops.Op");

    py::class_<ngraph::op::OneHot, std::shared_ptr<ngraph::op::OneHot>, ngraph::op::RequiresTensorViewArgs> onehot(m, "OneHot");
    onehot.def(py::init<const std::shared_ptr<ngraph::Node>&, const ngraph::Shape&, size_t>());
    onehot.def("get_one_hot_axis", &ngraph::op::OneHot::get_one_hot_axis);

}

