n,m=map(int,input().split())
c=0
while n!=0 and m!=0:
    n-=1
    m-=1
    c+=1
if c%2==0:
    print("Malvika")
else:
    print("Akshat")
