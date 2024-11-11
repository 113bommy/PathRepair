n=int(input())
t=0
z=0
for i in range(n):
    a,b=map(int,input().split())
    if a>b:
        t+=1
    elif a<b:
        z+=1
if t>z:
    print("Mishka")
elif z>t:
    print("Chris")
else:
    print("Friendship is magic!^^")