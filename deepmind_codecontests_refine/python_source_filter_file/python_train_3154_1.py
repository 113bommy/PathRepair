
def readline():
	return map(int,input().split())
if __name__ == "__main__":
	#code goes below
	for _ in range(int(input())):
		n=int(input())
		a=[0]+list(readline())
		ans=0
		for  i in range(2,n+1):
			ans+=abs(a[i]-a[i-1])
		mx=max(abs(a[2]-a[1]),abs(a[n]-a[n-1]))
		for i in range(2,n):
			mx=max(mx,abs(a[i]-a[i-1])-abs(a[i+1]-a[i])-abs(a[i+1]-a[i-1]))
		print(ans-mx)