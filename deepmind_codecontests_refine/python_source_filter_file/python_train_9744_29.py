def roun(n):
	if n<int(n+0.5):
		return (int(n)+1)
	else:
		return (int(n))
# avg=roun(1.8)
# print(avg)
from math import ceil
n,k=map(int,input().split())
l=list(map(int,input().split()))
sl=sum(l)
i=1
no_of_k=0
avg=roun(sl/n)
# print(avg)
while avg<k:
	# i+=1
	avg=roun((sl+i*k)/(n+i))
	# print(avg)
	i+=1
	no_of_k+=1
	if avg==k:
		# print(avg)
		print(no_of_k)
		break
