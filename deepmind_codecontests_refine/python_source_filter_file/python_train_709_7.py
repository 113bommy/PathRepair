n=int(input())
a=list(map(int,input().split()))

o=0
f=0
for i in a:
    if i%4==0:
        f+=1
    elif i%2!=0:
        o+=1

if len(a)<=3:
    f+=1

print("Yes" if f>=o else "No")