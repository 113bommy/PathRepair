n, capacity, wastefull = list(map(int,input().split()))
a = list(map(int,input().split()))
c = capacity
w = wastefull
count = 0 
for i in range(n):
	
	if(a[i]<capacity):
		w =w-a[i] 
		if(w<=0):	
			count=count+1
			w=wastefull

	else:
		continue
print(count)