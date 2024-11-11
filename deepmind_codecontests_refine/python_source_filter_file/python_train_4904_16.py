from  collections import Counter
from math import  gcd
def f(a):
    arr=[i for i in range(1,a+1)]
    s=(a*(a+1))//2
    for j in range(a,0,-1):
        if gcd(s,s-j)>1:
            arr.pop(j-1)
            print("YES")
            print(1,j)
            print(len(arr),*arr)
            return ""
    return "NO"






a=int(input())
print(f(a))