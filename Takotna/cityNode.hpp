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
        CityNode();
        unsigned int getNumber()
        {
            return number;
        }

        void setNumber(int number)
        {
            number = number;
        }

        double getLatitude()
        {
            return latitude;
        }

        void setLatitude(double latitude)
        {
            latitude = latitude;
        }

        double getLongitude()
        {
            return longitude;
        }

        void setLongitude(double longitude)
        {
            longitude = longitude;
        }

        double getGraphx()
        {
            return graphx;
        }

        void setGraphx(double graphx)
        {
            graphx = graphx;
        }

        double getGraphy()
        {
            return graphy;
        }

        void setGraphy(double graphy)
        {
            graphy = graphy;
        }

};