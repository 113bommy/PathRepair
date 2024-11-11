import math
def fact(n):
    ans = 1
    for i in range(2, n+1):
        ans*= i
    return ans
def comb(n, c):
    return fact(n)//(fact(n-c)*c)

n = int(input())
nums= list(map(int, input().split()))
m= 0
ans = []
for i in range(n-1, -1, -1):
    if(nums[i] < m):
        ans.append(str(m-nums[i]+1))
    else:
        ans.append('0')
    m =max(m, nums[i])
ans = ans[::-1]
print(' '.join(ans))
