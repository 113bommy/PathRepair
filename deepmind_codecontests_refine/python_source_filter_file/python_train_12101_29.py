import math

for t in range(int(input())):
    n, k = map(int, input().split())
    ans = ["a" for i in range(n)]
    
    firstB = int(math.ceil(-1+math.sqrt(1+8*k))/2)
    secB = k-(firstB*(firstB-1))//2
    ans[n - (firstB+1)] = "b"
    ans[n - secB] = "b"
    
    print("".join(ans))

