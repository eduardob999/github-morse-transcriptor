# include <iostream>
# include <iostream>
using namespace std;

class matrix {
    private:
        int size;
    public:
        void cMatrix( matrix self, int size );
        int getSize();
};

class control {
    public:
        void inputE( int& n );
};

class exercise {
    public:
        int main() {
                matrix M; int size;
                M.cMatrix( M, size );
            return 0;
        }
};

void cMatrix( matrix self, int& size ) {
    control c;
    c.inputE( size );
};