a,b=map(int,input().split())
aa=a
bb=a
x=0
y=0
while aa>0 and bb>0:
	if aa>bb:
		aa-=1
		x+=1
	else:
		bb-=1
		y+=1
	aa-=1
	bb-=1
if aa!=0 or bb!=0:
	print(0)
	exit()
mod=10**9+7
fac=[1]
for i in range(max(a,b)):
	fac.append(fac[i]*(i+1)%mod)
x+=y
r=pow(fac[y]*fac[x-y]%mod,mod-2,mod)
print(fac[x]*r%mod)
