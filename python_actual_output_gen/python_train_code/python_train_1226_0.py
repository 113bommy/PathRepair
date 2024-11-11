n,p=map(int,input().split())
#print("{0:b}".format(n))
ones="{0:b}".format(n).count('1')
t=0
while (ones>t ) and n>0:
    n-=p
    t+=1
    ones = "{0:b}".format(n).count('1')
if n<=0:
    print(-1)
else:
    print(t)

