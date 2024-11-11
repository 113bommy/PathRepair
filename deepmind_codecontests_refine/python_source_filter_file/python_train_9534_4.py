def main():

	def sum(x):
		res = 0

		while x > 0:
			res += x % 10
			x /= 10
		return res

	n = input()
	first = n[0]
	p = [1]

	for i in range(1, 20):
		p.append(p[-1] * 10)

	data = []	
	for i in range(len(n)):
		if i > 0 and n[i] == '0':
			continue
		temp = n[:i] + str(max(0, int(n[i]) - 1)) + "9"* (len(n) - i - 1)
		data.append((sum(int(temp)), int(temp)))

	data.append((sum(int(n)), n))
	
	data.sort(reverse=True)

	print(data[0][1])

	return

if __name__ == '__main__':
	main()	
