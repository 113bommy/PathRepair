#A
def main():
	from sys import stdin,stdout
	import math
	n,k=map(int,stdin.readline().split())
	rm=(240-k)//n
	#print(rm)
	ans=(-1+math.sqrt(1+8*rm))//2
	stdout.write(str(int(ans)))
if __name__=='__main__':
	main()
