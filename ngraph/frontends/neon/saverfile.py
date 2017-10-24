#!/usr/bin/env python
# ----------------------------------------------------------------------------
# Copyright 2017 Nervana Systems Inc.
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ----------------------------------------------------------------------------
import os
import numpy as np

class SaverFile(object):
    def __init__(self, Name="weights"):
        self.Name = Name
        super(SaverFile, self).__init__()
    
    def write_values(self, tensors):
        np.savez(self.Name, **tensors)

    def read_values(self):
        tensors = dict()
        filename = self.Name+".npz"
        with np.load(filename) as npzfile:
            for file in npzfile.files:
                tensors[file] = npzfile[file]
        return tensors


        
