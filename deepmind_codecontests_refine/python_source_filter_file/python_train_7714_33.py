L = list(map(int,input().split()))
n = L[0]
m = L[1]
k = 1
print("YES")
for i in range((m-n+1)//2):
	print(k,k+1)
	k += 2
		