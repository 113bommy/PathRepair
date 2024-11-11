import math

n,k = map(int, input().split())

c = 10**9+7

def cmb(n,r):
    return math.factorial(n) / (math.factorial(n-r)*math.factorial(r))


for i in range(k):
    try:
        print(int((cmb(k-1,i)*cmb(n - k+1,i+1))%c))
    except:
        print(0)