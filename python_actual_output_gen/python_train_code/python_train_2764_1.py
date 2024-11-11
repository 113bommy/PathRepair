n = int(input())
arr = [int(x) for x in input().split()]
arr_sum = sum(arr)
ans = arr_sum / (n * 100)
print(ans)