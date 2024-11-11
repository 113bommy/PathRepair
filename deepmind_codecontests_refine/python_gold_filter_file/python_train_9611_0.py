for _ in range(int(input())):
    n=int(input())
    s=list(map(int,input().split()))
    s.sort()
    s1=sum(s)-s[-1]*2
    if s1 in s[:-1]:
        s.remove(s1)
        print(*s[:n])
    else:
        if sum(s[:n])==s[n]:
            print(*s[:n])
        else:print("-1")