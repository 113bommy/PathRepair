n=int(input())
m=int(input())
k=int(input())
c=0
while( n>0 and n%k!=0):
    n=n-m
    c+=1
if(n>0):
    print("YES")
    print(c,n//k)
else:
    print("NO")

