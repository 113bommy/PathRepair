import sys 
from collections import Counter

# sys.stdin = open('input.txt', 'r')  
# sys.stdout = open('output.txt', 'w') 

n,l=map(int,input().split())
arr=list(map(int,input().split()))
for i in range(1,n):
	arr[i]=min(2*arr[i-1],arr[i])
# print(arr)

cost=0
ans=9999999999999999999
for i in range(n-1,-1,-1):
	# print(cost,i)
	cost+=arr[i]*(l//(2**i))
	l=l%(2**i)

	ans=min(ans,cost+(l>0)*arr[i])

print(ans)