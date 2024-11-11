t=int(input())
for i in range(t):
    l,r=input().split()
    l=int(l)
    r=int(r)
    if l*2<=r:
        print(l,r)
    else :
        print("-1 -1")
        