#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>

struct StockDataType{
	int date;
	int openPrice;
	int highestPrice;
	int lowestPrice;
	int closePrice;
	int unused1;
	int vol;
	int unused[3];
};

class Date{
	public:
		Date():year(0),month(0),day(0) {}
		~Date(){}
		Date(int d){
			year = d/10000;
			d = d%10000;
			month = d/100;
			d = d % 100;
			day = d;
		}
		std::string toString(){
			char buf[128];
			sprintf(buf, "%d-%d-%d", year, month, day);
			return std::string(buf);
		}
		bool operator == (const Date& r){
			return this->year == r.year &&
					this->month == r.month &&
					this->day == r.day;
		}
	private:
		int year;
		int month;
		int day;
};


std::string floatToString(float& f)
{
	std::stringstream ss;
	
	ss<<f;
	return ss.str();
}

class SDT{
	public:
		SDT(const struct StockDataType& stock);
		SDT();
		~SDT(){}
		std::string toString();
	private:
		Date m_date;
		float m_openingPrice;
		float m_closingPrice;
		float m_topPrice;
		float m_floorPrice;
		long  m_volume;
};

SDT::SDT()
	: m_date()
	, m_openingPrice(0)
	, m_closingPrice(0)
	, m_topPrice(0)
	, m_floorPrice(0)
	, m_volume(0)
{
}

SDT::SDT(const struct StockDataType& stock)
	: m_date(stock.date)
	, m_openingPrice(stock.openPrice/1000.0)
	, m_closingPrice(stock.closePrice/1000.0)
	, m_topPrice(stock.highestPrice/1000.0)
	, m_floorPrice(stock.lowestPrice/1000.0)
	, m_volume(stock.vol)
{	
}


std::string SDT::toString()
{
	std::string result;

	result += "Class SDT contents:\n";
	result += "\tdate: ";
	result += m_date.toString();
	result += "\n\topeningPrice: ";
	result += floatToString(m_openingPrice);
	result += "\n\tclosingPrice: ";
	result += floatToString(m_closingPrice);
	result += "\n\ttoPrice: ";
	result += floatToString(m_topPrice);
	result += "\n\tfloorPrice: ";
	result += floatToString(m_floorPrice);
	result += "\n\tvolume: ";
	result += floatToString(m_volume);
	result +="\n";
	return result;
}

int main(int argc, char** argv) {
	const char* filename = NULL;
	if (argc >= 2) {
		filename = argv[1];
	} else {
		std::cout<<"must input the stock data file!!";
		exit (1);
	}
	FILE* fp = fopen(filename, "r");
	struct StockDataType d;

	if (!fp) {
		std::cout<<"cannot open file 600887, just return;"<<std::endl;
		exit (1);
	}
	memset(&d, sizeof(struct StockDataType), 0);
	fread(&d, sizeof(d), 1, fp);
	fclose (fp);
	SDT a(d);
	std::cout<<a.toString();
	return 0;
}
