n=int(input())

inp=input().split();

arr=[] #skills 

for i in range(n):
	arr.append(int(inp[i]))

sum=0;

arr.sort();

#print(arr)

for i in range(0,n-1,2):
	sum+=(arr[i+1]-arr[i]);


print(sum)
