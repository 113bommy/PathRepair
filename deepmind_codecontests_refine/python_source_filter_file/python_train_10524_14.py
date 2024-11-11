a=int(input())
x=int(0)
m=[]
while x<a:
    b=list(map(int,input().split()))
    m.append((sum(b)))
    x=x+1
c=m[0]    
m=sorted(m, reverse=True)
print(m,c,m.index(c)+1)