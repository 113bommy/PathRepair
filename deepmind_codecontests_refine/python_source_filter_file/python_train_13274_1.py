inv=lambda t:''.join('*'if u=='+'else'+'for u in t)
n=int(input())
r=['++','+*']
for _ in range(n-1):
	r=[r[i] * 2 for i in range(len(r))] + [r[i]+inv(r[i]) for i in range(len(r))]
print(*r,sep='\n')