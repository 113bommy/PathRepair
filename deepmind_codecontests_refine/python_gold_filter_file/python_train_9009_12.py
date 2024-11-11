n = int(input())
a =[]
b =[]
for i in range(n):
	a.append(int(input()))
	b.append(a[len(a)-1])
a.sort()
b.sort()
b.reverse()
sum = 0
for i in range(n):
	sum+=(a[i]*b[i])
	sum%=10007
print(sum)