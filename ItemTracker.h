#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <map>
#include <string>

class ItemTracker {
private:
    // The map links each item to its purchase count
    std::map<std::string, int> itemFrequencies;

    void loadData(const std::string& filename);
    void saveBackup(const std::string& filename);

public:
    // this triggers the file reading when the object is created
    ItemTracker(const std::string& inputFilename);

    // main menu actions required by the rubric
    int getItemFrequency(const std::string& item);
    void printAllFrequencies();
    void printHistogram();
};

#endif