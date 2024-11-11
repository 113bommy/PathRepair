from functools import reduce

def factors(n):    
    return set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))
from math import gcd
S = input()
T = input()
s = len(S)
t = len(T)
if(S.count(S[0]) == s and T.count(S[0]) == t):
    print(len(factors(gcd(t,s))))
else:
    if(gcd(t,s) == 1):
        print(0)
    else:
        count = 0
        X = list(factors(gcd(t,s)))
        for i in X:
            if ((S[:i]*int((s/i))) == S) and (S[:i]*int(t/i) == T):
                count+=1
        print(count)
                

