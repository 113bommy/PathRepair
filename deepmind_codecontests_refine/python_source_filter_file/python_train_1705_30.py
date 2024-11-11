n,m = map(int,input().split())
mini = min(n,m)
print(mini+1)
current = 0
for i in range(mini+1,0,-1):
	print(i,current)
	current+=1