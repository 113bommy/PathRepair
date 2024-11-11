store=""
j=0
n,k=map(int,input().split())
for i in range(65,65+n):
	if len(store)<k:
		store+=chr(i)
	else:
		store+=store[j]
		j+=1
print(store)
		
