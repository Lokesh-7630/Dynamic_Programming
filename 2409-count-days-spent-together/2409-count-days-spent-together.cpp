class Solution {
    
private:
    const std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Helper function to convert "MM-DD" string into the day number of the year (1 - 365)
    int dateToDayOfYear(const std::string& date) {
        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(3, 2));

        int dayOfYear = day;
        for (int i = 0; i < month - 1; ++i) {
            dayOfYear += daysInMonth[i];
        }
        return dayOfYear;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceStart = dateToDayOfYear(arriveAlice);
        int aliceEnd   = dateToDayOfYear(leaveAlice);
        int bobStart   = dateToDayOfYear(arriveBob);
        int bobEnd     = dateToDayOfYear(leaveBob);

        // Overlap starts at the latest arrival and ends at the earliest departure
        int overlapStart = std::max(aliceStart, bobStart);
        int overlapEnd   = std::min(aliceEnd, bobEnd);

        if (overlapStart > overlapEnd) {
            return 0; // No overlap
        }

        return overlapEnd - overlapStart + 1;
    

    }
};