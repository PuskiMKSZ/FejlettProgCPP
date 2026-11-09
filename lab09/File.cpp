//
// Created by markt on 2026. 11. 09..
//

#include "File.h"
using namespace std;

File::File(const std::string &name, long size): FileSystemItem(name) {}

long File::getSize()const {
    return size;
}

void File::display(std::ostream &os, int depth) const {
    os << string(depth,' ') << name << " (" << size << "bajt)";
}
FileSystemItem* File::clone() const {
    return new File(*this);
}
