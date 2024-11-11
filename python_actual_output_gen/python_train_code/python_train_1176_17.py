k=int(input())

now=7
for i in range(k+10):
	if now==0:
		print(i+1)
		exit()
	now*=10
	now+=7
	now%=k
print(-1)