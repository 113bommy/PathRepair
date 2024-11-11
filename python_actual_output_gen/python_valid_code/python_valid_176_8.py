x,y = map(int, input().split())
n = int(input())
tmp = n%6

arr = [x,y,0,0,0,0]
for i in range(2,5):
	arr[i]=arr[i-1]-arr[i-2]
print(arr[tmp-1]%100000007)