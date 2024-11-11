n = int(input())
lis = []

def cek(n) :
	if n < 3 :
		return False
	if n%3 == 0 or n%7==0 :
		return True
	else :
		for i in range(1,100) :
			for j in range(1,100) :
				if (i*3)+(j*7) == n :
					return True
	return False

for i in range(n) :
	lis.append(int(input()))

for i in range(n) :
	if cek(lis[i]) :
		print("YES")
	else :
		print("NO")