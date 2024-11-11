getInputList = lambda : list(input().split())
getInputIntList = lambda : list(map(int,input().split()))

n ,k = getInputIntList()
arr = getInputIntList()
new = []
for i in arr:
	new.append(n%i)
index = new.index(min(new))+1 	
print(index,int(n/arr[index-1]))	