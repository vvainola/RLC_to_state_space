// MIT License
//
// Copyright (c) 2024 vvainola
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include <string>
#include <vector>
#include <functional>

namespace rlc2ss {

std::string readFile(const std::string& filename);
std::string replace(const std::string& original, const std::string& search, const std::string& replacement);
std::vector<double> getCommaDelimitedValues(std::string const s);
std::string loadTextResource(int resource_id);
double evaluateExpression(std::string expression);

struct ZeroCrossingEvent {
    double time;
    std::function<void(void)> event_callback;
    bool operator<(ZeroCrossingEvent const& other) const {
        return time < other.time;
    }
    bool operator>(ZeroCrossingEvent const& other) const {
        return time > other.time;
    }
};

double calcZeroCrossingTime(double y1, double y2);

} // namespace rlc2ss
