#ifndef __ARRAY_H__
#define __ARRAY_H__


namespace {
    int BUF_SIZE = 4;
    int BUF_COUNT = 3;
}


class Array {
    private:
        char *data;
        int len;
        int bufSize;
        int bufCount;
    public:
        Array(int bufSize = BUF_SIZE, int bufCount = BUF_COUNT);
        Array(const Array& other);
        Array& operator=(const Array& other);
        Array& operator-=(const Array& other);
        Array operator-(const Array& other);
        ~Array();
        void append(char data);
        char pop(int index = -1);
        void print();
};


#endif

