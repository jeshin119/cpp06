#ifndef __DATA_H__
#define __DATA_H__

class Data{
	private:
		int	_data;
	public:
		Data();
		Data(int data);
		~Data();
		Data(const Data& rhs);

		Data&	operator=(const Data& rhs);
};

#endif