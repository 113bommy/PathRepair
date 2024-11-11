for i in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    s=l.copy()
    s.sort(reverse=True)
    # print(s)
    if(l==s and len(set(l))==n):
        print("NO")
    else:
        print("YES")