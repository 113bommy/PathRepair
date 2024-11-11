def res(n, k):
     max_res = min(n, k - 1)
     min_res = max(1, k - max_res)
     return max(0, (max_res + 1 - min_res) // 2)

num = [int(i) for i in input().split(' ')]
print(*num)
