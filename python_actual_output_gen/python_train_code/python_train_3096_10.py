# Uses python3
import sys

def FastModularExponentiation(b, e, m) :
    res = 1     # Initialize result
 
    # Update x if it is more
    # than or equal to p
    b = b % m 
 
    while (e > 0) :
         
        # If y is odd, multiply
        # x with result
        if ((e & 1) == 1) :
            res = (res * b) % m
 
        # y must be even now
        e = e >> 1      # y = y/2
        b = (b * b) % m
    return res
if __name__ == '__main__':
    m = int(sys.stdin.read())
    n =(1+ FastModularExponentiation(2,m%5,5)+FastModularExponentiation(3,m%5,5)+
    FastModularExponentiation(4,m%5,5))%5
    print(n)
