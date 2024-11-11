t=int(input())
s=int(input())
v=int(input())
j=int(input())

m1=int(input())
m2=int(input())

c=0
f=0
if(m1<m2):
         f=1
cost=0
while(c<2):
         if(f==0):
                  p1=min(t,j)
                  cost+=p1*m1
                  j-=p1
                  f=1
                  c+=1
         if(f==1):
                  p1=min(s,v)
                  p2=min(p1,j)
                  cost+=p2*m2
                  f=0
                  j-=p2
                  c+=1
print(cost)
