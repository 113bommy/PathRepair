n=int(input())
m=0
c=0
d=0
for i in range(n):
    a,b=map(int,input().split())
    if a>b:
        m+=1
    elif a==b:
        d+=1
    else:
        c+=1
if m>c:
    print('Mishka')
elif m==c:
    print('Friendship is magic!^^')
else:
    print('Chirs')