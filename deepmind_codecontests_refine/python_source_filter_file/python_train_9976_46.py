n=int(input())
list=[]
for i in range(32):
	for j in range(10):
		ans=i**j
		if ans<=n:
			list.append(ans)
print(max(list))