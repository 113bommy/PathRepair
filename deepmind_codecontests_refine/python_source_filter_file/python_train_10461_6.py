k,n,w=map(int, input().split(' '))
cost=k*w*(w+1)//2
if ((cost-n)>=0) :print(cost-n)
else: print()
