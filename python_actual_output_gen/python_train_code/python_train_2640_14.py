n = int(input())
arr = list(map(int, input().split()))
left, right = arr[0], arr[-1]
i, j = 0, n-1
Max = 0
while(i <= j):
    if left == right:
        Max = left
        i, j = i+1, j-1
        left += arr[i]
        right += arr[j]
        
    elif left < right:
        i += 1
        left += arr[i]
    else:
        j -= 1
        right += arr[j]
        
print(Max)