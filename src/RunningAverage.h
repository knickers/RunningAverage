#ifndef RunningAverage_h
#define RunningAverage_h

class RunningAverage {
	public:
		RunningAverage(unsigned int size);
		~RunningAverage();
		void fill(int value);
		float append(int value);
	private:
		unsigned int mSize;
		unsigned int mI;
		int mTotal;
		int *mValues;
};

#endif
