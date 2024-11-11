for _ in range(int(input())):
    n = int(input())
    s = list(input())
    k = [i for i in range(n) if s[i]=="1"]
    ans = 0
    for i in k:
        ans = max(ans, 2*max(i+1,n-i))
    print(ans)
            