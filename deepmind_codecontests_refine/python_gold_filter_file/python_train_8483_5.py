a,b=map(int,input().split())

c=abs(a-b)

if(c%2==0):
    print('{0} {1}'.format(min(a,b),c//2 ))
else:
    print('{0} {1}'.format(min(a,b),c//2))