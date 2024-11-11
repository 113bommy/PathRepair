l = input()
a,b = input().split()
a = int(a)
b= int(b)
n = len(l)
ra = []
rb = [0]*n
nn = ""
f = 0
p = 1
ra.append(int(l[0])%a)
rb[n-1] = (int(l[n-1])%b)
for i in range(1,n-1):
	ra.append((ra[i-1]*10+int(l[i]))%a)
for i in range(n-2,-1,-1):
	rb[i] = (rb[i+1] + (int(l[i])*p*10)%b)%b
	p = (p*10)%b
for i in range(n-1):
	if(ra[i] ==0 and rb[i+1] == 0 and l[i+1] != "0"):
		print("YES")
		print(l[:i+1])
		print(l[i+1:n])
		f = 1
		break
if(f== 0):
	print("NO")