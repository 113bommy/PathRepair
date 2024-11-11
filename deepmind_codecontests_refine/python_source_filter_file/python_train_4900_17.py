n = int(input())
for i in range(n + 1):
	if i % 3 == 0 or str(i).find("3") != -1:
		print(" {}".format(i), end = '')
print()
