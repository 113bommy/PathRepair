n,p=map(int,input().split())
#print("{0:b}".format(n).count('1'))
t=0
while (("{0:b}".format(n).count('1'))>t or n<t) and (n-p)>=0:
    t+=1
    n-=p
if n==0:
    print(-1)
else:
    print(t)
