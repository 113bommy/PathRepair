i,o,t,j,l,s,z=map(int,input().split())
ans=0
ans+=o
if j==1 and l==1 and i==1:
    ans+=3
elif j<2 or l<2 or i<2:
    ans+=0
elif j%2==1 and l%2==1 and i%2==1:
    ans+=j+i+l
elif j%2==1 and l%2==1 and i%2==0:
    ans+=j+i+l-1
elif j%2==1 and l%2==0 and i%2==1:
    ans+=j+i+l-1
elif j%2==1 and l%2==0 and i%2==0:
    ans+=j+i+l-1
elif j%2==0 and l%2==1 and i%2==1:
    ans+=j+i+l-1
elif j%2==0 and l%2==1 and i%2==0:
    ans+=j+i+l-1
elif j%2==0 and l%2==0 and i%2==1:
    ans+=j+i+l-1
elif j%2==0 and l%2==0 and i%2==0:
    ans+=j+i+l
print(ans)
