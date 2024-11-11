def main():

	n=int(input())
	ip=[int(item) for item in input().split(" ")]
	ip.sort()

	cnt=1
	sum_ip=ip[0]
	for i in range(1,len(ip)):
		if ip[i]>=sum_ip:
			cnt+=1
		sum_ip+=ip[i]

	print(cnt)	



if __name__=="__main__":
	main()
