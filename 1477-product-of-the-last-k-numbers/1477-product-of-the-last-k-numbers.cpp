class ProductOfNumbers {
public:
    vector<int> stream;
    ProductOfNumbers() {
        // initialise object with empty stream
    }

    void add(int num) {
        // Appends the integer num to the stream
        stream.push_back(num);
    }

    int getProduct(int k) {
        // Returns the product of the last k numbers in the current list
        int n = stream.size();
        int product = 1;
        for (int i = n - 1; i >= n - k; i--) {
            product *= stream[i];
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */