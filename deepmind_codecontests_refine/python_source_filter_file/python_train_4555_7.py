'''for _ in range(int(input())):
	n,a,b=map(int,input().split())
	for i in range(n):
		print(chr(97+i%b),end='')
	print()
	'''
n=int(input())
arr=sorted(list(map(int,input().split())))
ans=sum(arr)
if round(ans/n)>=5:
	print(0)
	exit()
for i in range(n):
	ans-=arr[i]
	ans+=5
	if ans/n>=4.5:
		print(i+1)
		break

