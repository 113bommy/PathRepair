n,k = map(int,input().split());cnt=0;arr2=[]
arr = [list(map(int,input().split())) for i in range(n)]
for i in range(n):
    cnt+=min(arr[i][0],arr[i][1])
    arr2.append(min(arr[i][0]*2,arr[i][0])-min(arr[i][0],arr[i][1]))
arr2 = list(reversed(sorted(arr2)))
for i in range (k):
    cnt+=arr2[i]
print(cnt+2)