for i in range(int(input())):
	q = list(map(int, input().split()))
	w = ["Ya", "Ya", "Ya", "Ya"]

	if q[0] + q[1] % 2 == 0:
		w[0] = "Tidak"
		w[1] = "Tidak"
	else:
		w[2] = "Tidak"
		w[3] = "Tidak"

	if q[0] == 0 and q[3] == 0:
		w[0] = "Tidak"
		w[3] = "Tidak"
	if q[1] == 0 and q[2] == 0:
		w[1] = "Tidak"
		w[2] = "Tidak"

	print(*w)