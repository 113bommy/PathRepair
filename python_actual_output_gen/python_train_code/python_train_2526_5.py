for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if a==sorted(a,reverse=True) and len(set(a))!=1:
        print("NO")
    else:
        print("YES")