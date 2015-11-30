typedef struct _StockDataType{
	int date;
	int openPrice;
	int highestPrice;
	int lowestPrice;
	int closePrice;
	int unused1;
	int vol;
	int unused2;
}StockDataType;

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


class SDT{
	public:
		SDT(const StockDataType& stock);
		SDT();
		~SDT(){}
		std::string toString();
		void set20Max(float max){m_20Max = max;}
		float tweenMax(){return m_20Max;}
		void set20Min(float min){m_20Min = min;}
		float tweenMin(){return m_20Min;}
		void set20Avr(float avr){m_20Average = avr;}
		float tweenAvr(){return m_20Average;}
		float closingPrice(){return m_closingPrice;}
		float openingPrice() {return m_openingPrice;}
		float topPrice(){return m_topPrice;}
		float floorPrice(){return m_floorPrice;}
	private:
		Date m_date;
		float m_openingPrice;
		float m_closingPrice;
		float m_topPrice;
		float m_floorPrice;
		float m_volume;

		float m_20Max;
		float m_20Min;
		float m_20Average;
};


