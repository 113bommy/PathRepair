import math;
N=list(map(int,input().split()));
n=N[0];
k=N[1];

d=math.ceil(n/(2*(k+1)));
c=k*d;

w=n-c-d;

print(d,c,w,end=" ");
