_,a=open(0);*a,=map(int,a.split());t=sum(a)-2*sum(a[1::2]);x=[t]
for i in a:t=i*2-t;x+=t,
print(*x[:-1])