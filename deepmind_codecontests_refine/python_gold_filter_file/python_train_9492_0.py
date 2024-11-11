def mdc(u, v):
    while v: # até v == 0, ou seja resto == 0
        u, v = v, u % v
    return abs(u)


n = int(input())

lis = list(map(int, input().split()))
md = div = 0

for i in lis:
	md = mdc(md,i)


for i in range(1,int(md**0.5) + 1): # calcula o número de divisores do mdc
	if md%i == 0 and i**2 != md: # garante que o mesmo numero não seja contado duas vezes
		div += 2
	elif md%i == 0:
		div +=1 

print(div)