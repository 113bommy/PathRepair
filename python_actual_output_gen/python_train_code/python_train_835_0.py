n=int(input())-1;a=0
for i in range(0,35):
	k=1<<i;a+=k*((n+(k<<1)-k)//(k<<1))
print(a)