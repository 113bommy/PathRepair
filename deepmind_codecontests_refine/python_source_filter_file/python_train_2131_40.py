import math
def fact(n):
    ans = 1
    for i in range(2, n+1):
        ans*= i
    return ans
def comb(n, c):
    return fact(n)//(fact(n-c)*c)

n = int(input())
ans = 0
for i in range(10):
    if('8' in str(n) and i!= 0):
        break
    else:
        ans+=1
        n+=1
print(ans)
