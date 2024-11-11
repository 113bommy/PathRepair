N = int(input())
lst = [int(i) for i in input().split()]
mod = 1000000007
count = [0] * (N + 1)
count[0] = 3

ret = 1
for i in lst:
    count[i + 1] += 1
    ret = (ret * count[i]) % mod
    count[i] -= 1

print(ret)