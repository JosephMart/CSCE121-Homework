class Data {
    int Location;
    int Year;
    int Month;
    double tempValue;

public:
    void setLocation(int Location) {this->Location = Location;}
    void setYear(int Year) {this->Year = Year;}
    void setMonth(int Month) {this->Month = Month;}
    void setValue(double tempValue) {this->tempValue = tempValue;}

    int getLocation() const {return Location;}
    int getYear() const {return Year;}
    int getMonth() const {return Month;}
    double getValue() const {return tempValue;}
};