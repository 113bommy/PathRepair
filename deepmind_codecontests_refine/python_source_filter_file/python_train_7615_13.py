if __name__ == '__main__':
	t=int(input())
	for i in range(t):
		riga=input()
		n=int(riga.split()[0])
		k=int(riga.split()[1])
		step=0
		while(n>0):
			r= n % k
			if r == 0:
				n/=k
				step+=1
			else:
				n-=r
				step+=r
		print(step)
