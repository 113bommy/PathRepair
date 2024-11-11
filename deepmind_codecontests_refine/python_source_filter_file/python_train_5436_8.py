import math
mac=10**9+7
def comb(a,b):
    return math.factorial(a)//math.factorial(b)*math.factorial(a-b)
n,m=map(int,input().split())
print(comb(2*m+n-1,2*m)%mac)
