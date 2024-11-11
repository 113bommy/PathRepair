def solve(n, p):
    ans = [0] * n
    
    for i in range(n):
        d = 0
        j = p[i]-1
        d+=1
        while j!=i:
            d+=1
            j = p[j]-1
        ans[i] = str(d)
    print(" ".join(ans))


for _ in range(int(input())):
    n = int(input())
    p = list(map(int, input().split()))
    print(solve(n,p))
