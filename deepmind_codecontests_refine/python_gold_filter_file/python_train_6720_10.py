n=int(input())
a=[]
b=[]
c=0
for i in range(n):
    s=[str(x) for x in input().split()]
    a.append(s[0])
    b.append(s[1])
for i in range(n):
    if a[i]>b[i]:
            c+=1
    elif a[i]<b[i]:
            c-=1
if c>0:
    print('Mishka')
elif c==0:
    print('Friendship is magic!^^')
else:
    print('Chris')