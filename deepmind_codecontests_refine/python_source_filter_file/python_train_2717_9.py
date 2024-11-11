n = int(input())
arr = [int(x) for x in input().split()]

if n == 1:
    print(arr[0])
    exit()
    
sum = sum(abs(x) for x in arr)

if not any(x<0 for x in arr):
    sum = sum - 2 * min(arr)
if not any(x>=0 for x in arr):
    sum = sum - 2 * max(arr)
    
print(sum)