k=int(input())
l=int(input())
c=-1
r=k
while l%k==0:
    l=l//k
    c+=1

if l!=1:
    print("NO")
else:
    print("YES")
    print(c)
