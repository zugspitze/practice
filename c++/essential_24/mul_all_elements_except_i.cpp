// Implement a void function F that takes pointers to two arrays of
// integers (A and B) and a size N as parameters. It then populates
// B where B[i] is the product of all A[j] where j != i.

// For example: If A = {2, 1, 5, 9}, then B would be 
// {45, 90, 18, 10}.

// This problem seems easy at first glance so a careless developer 
// might write something like this:

void F(int* A, int* B, int N) {
    int m = 1;
    for (int i = 0; i < N; ++i) {
        m *= A[i];
    }
    
    for (int i = 0; i < N; ++i) {
        B[i] = m / A[i];
    }
}

// This will work for the given example, but when you add a 0 into
// input array A, the program will crash because of division by 
// zero. The correct answer should take that edge case into account 
// and look like this:

void F(int* A, int* B, int N) {
    // Set prod to the neutral multiplication element
    int prod = 1;
    
    for (int i = 0; i < N; ++i) {
        // For element "i" set B[i] to A[0] * ... * A[i - 1]
        B[i] = prod;
        // Multiply with A[i] to set prod to A[0] * ... * A[i]
        prod *= A[i];
    }
    
    // Reset prod and use it for the right elements
    prod = 1;
    
    for (int i = N - 1; i >= 0; --i) {
        // For element "i" multiply B[i] with A[i + 1] * ... * A[N - 1]
        B[i] *= prod;
        // Multiply with A[i] to set prod to A[i] * ... * A[N - 1]
        prod *= A[i];
    }
}

// The presented solution above has a Big O complexity of O(N). 
// While there are simpler solutions available (ones that would 
// ignore the need to take 0 into account), that simplicity has a 
// price of complexity, generally running significantly slower.
