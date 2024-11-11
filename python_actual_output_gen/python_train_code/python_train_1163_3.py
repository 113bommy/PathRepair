n=int(input())
p=[int(x) for x in input().split()]
q=[int(x) for x in input().split()]
t=0
for i in range(1,n+1):
    if i in p[1:] or i in q[1:]:
        t+=1
if t==n:
    print('I become the guy.')
else:
    print('Oh,my keyboard!')