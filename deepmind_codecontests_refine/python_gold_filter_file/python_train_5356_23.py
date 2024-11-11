p,n=map(int,input().split())
l=[]
for k in range(n):
    i=int(input())
    if i%p not in l:
        l.append(i%p)
    else:
        print(k+1)
        break
if len(l)==n:
    print("-1")
