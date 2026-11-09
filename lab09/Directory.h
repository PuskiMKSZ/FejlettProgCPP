//
// Created by markt on 2026. 11. 09..
//

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FileSystemItem.h"
#include <vector>

class Directory : public FileSystemItem {
private:
    std::vector<FileSystemItem*> children;

    void clearChildren();
    void copyChildren(const Directory& other);

public:
    Directory(const std::string& name);
    ~Directory() override;

    // Deep copy (Copy konstruktor és értékadó operátor)
    Directory(const Directory& other);
    Directory& operator=(const Directory& other);

    // Metódusok
    void add(FileSystemItem* item);
    void remove(const std::string& name);
    FileSystemItem* find(const std::string& name) const;

    long getSize() const override;
    void display(std::ostream& os = std::cout, int depth = 0) const override;
    FileSystemItem* clone() const override;

    // Operátorok
    Directory& operator+=(FileSystemItem* item);
    Directory& operator-=(const std::string& name);
};

#endif // DIRECTORY_H#ifndef CPP_2026_DIRECTORY_H
#define CPP_2026_DIRECTORY_H


