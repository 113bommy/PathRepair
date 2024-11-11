for _ in range(int(input())):
    n = int(input())
    s = str(input())
    ans = 0
    for i in range(n-1):
        if (int(s[i+1]) - int(s[i])) == 0 and int(s[i+1])==int(s[i])==1:
            ans += 1
        else :
            continue
    print(ans)
