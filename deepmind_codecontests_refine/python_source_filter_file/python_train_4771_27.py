N=int(input());t=[0]+[N]*N
for i in range(2,N+1):
 x,a,b=t[i-1],6,9
 while a<=i:x=min(x,t[i-a],(t[i-b]if b<=i else N));a*=6;b*=9
 t[i]=x+1
print(t[N])