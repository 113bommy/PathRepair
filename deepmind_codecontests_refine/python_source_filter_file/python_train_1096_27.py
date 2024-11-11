def main():
	N = int(input())
	arr = list(map(int,input().split()))
	mic ,mac =0,0
	for i in range(len(arr)):
		if arr[i]==1:
			mic = i
		if arr[i]==N:
			mac = i 
	temp = min(mac,mic)
	temp2 = max(mic,mac)
	if (temp)<(N-temp2):
		print(N-(temp+1))
	else:
		print(temp2+1)




	
main()