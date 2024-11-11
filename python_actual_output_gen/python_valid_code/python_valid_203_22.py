t = int(input())
for i in range(t):
    l,r = map(int,input().split())
    if l==0:
        print(0)
    elif l==1:
        print(r)
    else:
        print(2*r)