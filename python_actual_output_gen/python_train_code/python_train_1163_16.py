n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=a[1:]+b
s=set(c)
if len(s)==n:
    print('I become the guy.')
else:
    print('Oh, my keyboard!')