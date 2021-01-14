#ifndef RunningAverage_h
#define RunningAverage_h

class RunningAverage {
	public:
		RunningAverage(unsigned int size);
		~RunningAverage();
		void fill(float value);
		float append(float value);
	private:
		unsigned int mSize;
		unsigned int mI;
		float mTotal;
		float *mValues;
};

#endif
