n=int(input())
s=0
t=0
for i in range(n):
    a,b=[int(x) for x in input().split()]
    if a>b:
        s=s+1
    elif a<b:
        t=t+1
if s==t:
    print('Friendship is magic!^^')
elif s>t:
    print('Mishka')
else:
    print('Chris')

