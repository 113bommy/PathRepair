n=int(input())
a=list(map(int,input().split(" ")))
b=[]
for x in range(0,n-1):
    b.append(abs(a[x+1]-a[x]))
b.append(abs(a[n-1]-a[0]))
c=min(b)
if b.index(c)<n-1:
    print(f'{b.index(c)+1} {b.index(c)+2}')
else:
    print(f'{n} 0')