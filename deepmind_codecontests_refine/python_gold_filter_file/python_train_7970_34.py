#A
def main():
	from sys import stdin,stdout
	import math
	n,k=map(int,stdin.readline().split())
	rm=(240-k)//5
	#print(rm)
	ans=(-1+math.sqrt(1+8*rm))//2
	stdout.write(str(min(int(ans),n)))
if __name__=='__main__':
	main()
