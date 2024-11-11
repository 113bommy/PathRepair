def main():
	n, m =[int(i) for i in input().split()]
	arr= [int(i) for i in input().split()]
	if n==m:
		print(max(arr)-min(arr))
		return 0
	arr.sort()
	if n==m-1:
		print(min((arr[-1]-arr[1]),arr[-2]-arr[0]))
		return 0
	mi=9999999999999999
	i=0
	for i in range(1,(m-n+1)):
		mi= min((arr[i+n-1]-arr[i]),mi)		#arr[k], arr[k+1], .....arr[k+n-1]
		i+=1
	print(mi)
	return 0

if __name__ == '__main__':
	main()
