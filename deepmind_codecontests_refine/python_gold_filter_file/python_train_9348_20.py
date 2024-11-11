from math import factorial

n,k=map(int,input().split())

def f(n,k):
    return factorial(n)//(factorial(k)*(factorial(abs(n-k))))

for i in range(k):
    print(f(n-k+1,i+1)*f(k-1,i)%(10**9+7))