t = int(input())

def kvadrat_yuzi(a,b):
	a = min(a,b)
	b = max(a,b)
	if(2*a>=b):
		return 4*a*a
	else:
		return b*b

natija = []
for i in range(t):
	a,b = input().split(" ")
	a,b = int(a), int(b)
	natija.append(kvadrat_yuzi(a,b))

for i in range(t):
	print(natija[i])
