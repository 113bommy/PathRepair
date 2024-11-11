n=int(input())
m1=0
c1=0
for i in range(0,n):
    m,c=[int(x) for x in input().split()]
    if(m>c):
        m1=m1+1
    elif(c>m):
        c1=c1+1
if(m1>c1):
    print("Mishika")
elif(m1==c1):
    print("Friendship is magic!^^")
else:
    print("Chris")
