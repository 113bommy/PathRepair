t=int(input())
for _ in range(t):
    l,r=map(int,input().split())
    if l==r:
        print(0)
    else:
        k=r%2+1
        if k>=l:
            print(r%k)
        else:
            print(r%l)