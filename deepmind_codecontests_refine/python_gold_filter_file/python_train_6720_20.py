n=int(input())
m=0
c=0
for i in range(0,n):
    a,b=input().split(' ')
    if a>b:
        m+=1
    elif b>a:
        c+=1
if m==c:
    print("Friendship is magic!^^")
elif m>c:
    print("Mishka")
else:
    print("Chris")
