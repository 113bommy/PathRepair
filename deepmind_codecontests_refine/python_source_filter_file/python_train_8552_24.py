n=int(input())
l=list(map(int,input().split()))
c=0
while((sum(l[0:n]))==(sum(l[n:]))):
    a=l.pop(0)
    l.append(a)
    c=c+1
    if(c>=2*n+1):
        break
if(c>=2*n+1):
    print(-1)
else:
    print(*l)
    
