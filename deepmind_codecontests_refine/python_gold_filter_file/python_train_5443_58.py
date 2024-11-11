t=(int)(input())
for _ in range(t):
    # n=(int)(input())
    # l=list(map(int,input().split()))
    l,r=map(int,input().split())
    if r<2*l:
        print("YES")
    else:
        print("NO")