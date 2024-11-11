def factorial(x):
    ans=1
    for i in range(2,x+1):
        ans = (ans*i)%(10**9+7)
    return ans
n = int(input())
print((factorial(n) - pow(2,n-1,10*9+7))%(10*9+7))