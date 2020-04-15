class CityNode {
    private:
        unsigned int number;
        double latitude;
        double longitude;
        double graphx;
        double graphy;
    public:
        CityNode(unsigned int _number, double _latitude, double _longitude):
            number(_number), latitude(_latitude),longitude(longitude){};
    
};