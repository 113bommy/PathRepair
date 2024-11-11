def main():
	n = int(input())
	a = []
	for i in range(n):
		num = int(input())
		a.append(num)

	#b son los conteos de los diferentes numeros del vector
	c = list(set(a))
	b = list(map(a.count, list(set(a))))

	#c me dice cuantos hay de cada conteo y lo ordena
	#c = list(map(b.count, list(set(b))))
	#c.sort()

	if len(b) == 2 and b[0] == b[1]:
		print("YES")
		print(c[0], c[1])
	else:
		print("NO")

main()