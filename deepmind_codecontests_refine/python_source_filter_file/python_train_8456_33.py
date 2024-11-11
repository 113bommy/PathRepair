z=input;
from math import *
n1=int(z())
for _ in range(n1):
    n=int(z())

    for i in range(2,29):
        if (n%(2**i -1))==0:
            print(n//(2**i -1))
            break
        
