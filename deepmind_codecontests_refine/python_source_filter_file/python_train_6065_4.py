def main():
	check=set()
	count=0
	n=int(input())
	arr= [int(i) for i in input().split()]
	for i in arr:
		if i in check:
			count+=1
		else:
			check.add(i)
	print(count)
	return 0

if __name__ == '__main__':
	main()
