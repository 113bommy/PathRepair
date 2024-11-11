n,m=map(int,input().split())
arr=[]
for i in range(n):
    a,b=map(int,input().split())
    arr.append(a-b/100)
arr.sort()
arr.reverse()
# print(arr)
print(arr.count(arr[m-1]))