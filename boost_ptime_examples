#include <iostream>
#include "boost/date_time/posix_time/posix_time.hpp" 
#include "boost/date_time/gregorian/gregorian.hpp"

using namespace boost::posix_time;
using namespace boost::gregorian;




int main(){
    ptime today = second_clock::universal_time();
    ptime yesterday = boost::posix_time::second_clock::universal_time() - boost::gregorian::days(1);

    std::cout << today << std::endl;
    std::cout << yesterday << std::endl;

    
    std::cout << boost::posix_time::ptime(today.date(), boost::posix_time::time_duration(0,0,0)) << std::endl;

    try{
        // boost::posix_time::ptime createdAt3(boost::posix_time::from_iso_string("20160222T171819"));
        boost::posix_time::ptime createdAt3(boost::posix_time::from_iso_string("201602"));
    }catch(const std::exception& e){
            std::cout << e.what() << std::endl;
    }
}
