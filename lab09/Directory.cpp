#include "Directory.h"
#include <algorithm>

void Directory::clearChildren() {
    for (auto child : children) {
        delete child;
    }
    children.clear();
}

void Directory::copyChildren(const Directory& other) {
    for (auto child : other.children) {
        if (child != nullptr) {
            this->children.push_back(child->clone());
        }
    }
}

Directory::Directory(const std::string& name) : FileSystemItem(name) {}

Directory::~Directory() {
    clearChildren();
}

Directory::Directory(const Directory& other) : FileSystemItem(other.name) {
    copyChildren(other);
}

Directory& Directory::operator=(const Directory& other) {
    if (this != &other) {
        FileSystemItem::name = other.name;
        clearChildren();
        copyChildren(other);
    }
    return *this;
}

void Directory::add(FileSystemItem* item) {
    if (item != nullptr) {
        children.push_back(item);
    }
}

void Directory::remove(const std::string& name) {
    auto it = std::remove_if(children.begin(), children.end(), [&name](FileSystemItem* item) {
        if (item->getName() == name) {
            delete item;
            return true;
        }
        return false;
    });
    children.erase(it, children.end());
}

FileSystemItem* Directory::find(const std::string& name) const {
    if (this->name == name) {
        return const_cast<Directory*>(this);
    }
    for (auto child : children) {
        if (child->getName() == name) {
            return child;
        }
        Directory* dir = dynamic_cast<Directory*>(child);
        if (dir) {
            FileSystemItem* found = dir->find(name);
            if (found) return found;
        }
    }
    return nullptr;
}

long Directory::getSize() const {
    long totalSize = 0;
    for (auto child : children) {
        totalSize += child->getSize();
    }
    return totalSize;
}

void Directory::display(std::ostream& os, int depth) const {
    os << std::string(depth, ' ') << name << "/ (" << getSize() << " bytes)\n";
    for (auto child : children) {
        child->display(os, depth + 2);
    }
}

FileSystemItem* Directory::clone() const {
    return new Directory(*this);
}

Directory& Directory::operator+=(FileSystemItem* item) {
    add(item);
    return *this;
}

Directory& Directory::operator-=(const std::string& name) {
    remove(name);
    return *this;
}