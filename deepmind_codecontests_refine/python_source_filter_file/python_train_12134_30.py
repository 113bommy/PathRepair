def main():
	s = int(input())
	l = [int(i) for i in input().split()]
	biggest = 0
	greater = 1
	for i in range(s-1):
		if l[i] < l[i+1]:
			greater += 1
		elif l[i] >= l[i+1]:
			greater = 1
		biggest = max(greater, biggest)
	print(biggest)
main()