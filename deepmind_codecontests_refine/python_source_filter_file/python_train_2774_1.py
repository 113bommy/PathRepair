n, k = input().split()
n = int(n)
k = int(k)
a = []
s = input()
a = s.split()
q = (n // int(a[0]))
w = 0
for i in range(1,k):
	if (n // int(a[i]))*int(a[i]) > q*int(a[w - 1]):
		q = (n // int(a[i]))
		w = i + 1
print(str(w) + " " + str(q))
