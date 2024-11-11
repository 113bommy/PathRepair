int(input())
arr = list(map(int, input().split()))
n = len(arr)//2
arr.sort()
x1 = arr[0]
x2 = arr[n-1]
y2 = arr[-1]
y1 = arr[n]
ans = abs(x1-x2)*abs(y1-y2)
# print(arr)
for i in range(n,n*2-1):
    # print(i-n+1,i,'|',arr[i-n+1],arr[i])
    ans = min((arr[i]-arr[i-n+1])*(arr[i-1]-arr[0]),ans)
print(ans)
