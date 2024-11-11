n,k=map(int, input().split())
l1=[0 for i in range(n)]
x=0
for i in range(n):
    l1[x]=n
    print(' '.join(map(str, l1)))
    l1[x]=0
    x+=1