d=[1]+[0]*12
for c in input():
	e=[0]*13
	for k in([c],range(10))[c>'9']:
		for j in range(13):t=(j*10+int(k))%13;e[t]+=d[j];e[t]%=10**9+7
	d=e
print(d[5])