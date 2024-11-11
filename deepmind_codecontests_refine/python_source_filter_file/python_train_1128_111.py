N,*A=map(int,open(0).read().split());l=[0]*9
for a in A:l[min(8,a//400)]+=1
m=sum([0<l[i]for i in range(8)]);print(min(m,1),m+l[8])