n=int(input())
l=[]
if n<=2:
    print(-1)
else:
    for i in range(n,1,-1):
        l.append(i)
    for r in l:
        print(r,end=' ')