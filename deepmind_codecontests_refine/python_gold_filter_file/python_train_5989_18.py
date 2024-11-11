import math as m
v,s= [],0
n = int(input())
for _ in range(n):
	a = input()
	q =a.count("C")
	if q>=2:
		s+=int(m.factorial(q)/(m.factorial(2)*m.factorial(q-2)))
	v.append(a)
for i in range(n):
	z =""
	for j in range(n):
		z+=v[j][i]
		w = z.count("C")
	if w>=2:
		s+=int(m.factorial(w)/(m.factorial(2)*m.factorial(w-2)))
print(s)