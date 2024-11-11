def solve(n,arr):
	one=[]
	if arr.count(1)==len(arr):
		if len(arr)%2==0:
			print("Second")
		else:
			print("First")
	else:
		for i in arr:
			if i==1:
				one.append(i)
			else:
				break
		if len(one)%2==0:
			print("First")
		else:
			print("Second")

t=int(input())
for i in range(t):
	n=input()
	arr=list(map(int,input().split()))
	solve(n,arr)







