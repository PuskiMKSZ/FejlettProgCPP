//
// Created by markt on 2026. 11. 09..
//

#include "FileSystemItem.h"


FileSystemItem::FileSystemItem(const std::string& name) : name(name) {}

std::string FileSystemItem::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& os, const FileSystemItem& item) {
    item.display(os);
    return os;
}

bool FileSystemItem :: operator<(const FileSystemItem &other) const {

    return this->name> other.name;

}