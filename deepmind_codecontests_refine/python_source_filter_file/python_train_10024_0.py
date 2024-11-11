n=int(input())
arr=list(map(int,input().split()))
x=0
y=0
for i in range(n):
    if arr[i]<=arr[x]:
        x=i
    if arr[i]>=arr[y]:
        y=i
# x=arr.index(min(arr))
# y=arr.index(max(arr))
# print(x,y)
if x<=y:
    print(y+n-x-2)
else:
    print(y-x+n-1)

# print(x,y)