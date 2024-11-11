for _ in range(int(input())):
    l,r=map(int,input().split())
    if(r-l>=l):
        print("NO")
    else:
        print("YES")