t=int(input())
for x in range(t):
    l,r=map(int,input().split())
    if r<2*l:
        print("YES")
    else:
        print("NO")