fac = []
fac.append(1)
for i in range(1,778):
	fac.append(i*fac[i-1])
x = int(input())
ans = (fac[x]/(fac[5]*fac[x-5])) + (fac[x]/(fac[6]*fac[x-6])) + (fac[x]/(fac[7]*fac[x-7]))
print(int(ans))