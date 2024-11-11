n,d=map(int,input().split());a=list(map(int,input().split()));m=int(input());p=0;a.sort()
for i in range(n):
	p+=a[i];m-=1
	if m==0:break
if m>0:p-=m*d
print(p)