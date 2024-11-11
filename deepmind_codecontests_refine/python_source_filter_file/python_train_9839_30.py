def sumtwo(n):
    ans = 0
    i = 0
    while 2**i <= n:
        ans += 2**i
        i+=1
    return ans

t = int(input())
for _ in range(t):
    n = int (input())
    print (int(- 2*sumtwo(n) + (n+1) * n/2))