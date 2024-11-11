n = int(input())
arr = list(map(int,input().split()))
arr.sort()
count = arr[-1]-arr[0]+1
print(count - n)    