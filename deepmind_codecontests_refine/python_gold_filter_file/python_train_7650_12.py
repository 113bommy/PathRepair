
#for _ in  range(int(input())):
	#n, m = map(int, input().split())
n=int(input())
#arr= list(map(int, input().split()))
prime=[True]*(n+2)
prime[0]=False
prime[1]=False
pr=[]
for  i in range(2,n+1):
	if prime[i]:
		pr.append(i)
		for j in range(2*i,n+1,i):
			prime[j]=False
ch=[]
for p in pr:
	j=1
	while p**j<=n:
		ch.append(p**j)
		j+=1
print(len(ch))
print(*ch)