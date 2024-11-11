valores = input()
valores = valores.split(' ')
r = int(valores[-1])

n = input()
n = n.split(' ')
for i in range(len(n)):
    n[i] = int(n[i])

m = input()
m = m.split(' ')
for i in range(len(m)):
    m[i] = int(m[i])

if min(n) > max(m):
	print(r)
elif min(n) < max(m):
	print(r-((r//min(n))*min(n))+((r//min(n))*(max(m))))