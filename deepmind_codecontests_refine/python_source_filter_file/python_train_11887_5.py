n=int(input())
arr=[-1]*2*n
first=0
second=n
flag=0
val=1
for i in range(n):
	if(i%2==0):
		arr[first]=val
		arr[second]=val+1
		val+=2
		first+=1
		second+=1
	else:
		arr[second]=val
		arr[first]=val+1
		val+=2
		first+=1
		second+=1
print(*arr)
arr2=[]
sumx=0
for i in range(n):
	sumx+=arr[i]
arr2.append(sumx)
end=n
for i in range(2*n):
	sumx-=arr[i]
	sumx+=arr[end%(2*n)]
	end=end+1
	arr2.append(sumx)
#print(arr2)

minval=min(arr2)
maxval=max(arr2)
if(maxval-minval<=1):
	print("YES")
	print(*arr)
else:
	print("NO")
	#for i in range(2*n):

