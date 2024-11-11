def fun(arr):
    total = 2*n - 1
    for i in range(n-2):
        total += (arr[i]-arr[i+1]) * (arr[i+1]-arr[i+2]) < 0
    for i in range(n-3):
        total += ((arr[i+1]-arr[i+3])*(arr[i+3]-arr[i+2]) > 0 and (arr[i+1]-arr[i])*(arr[i]-arr[i+2]) > 0)
    print(total)




 
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    fun(arr)