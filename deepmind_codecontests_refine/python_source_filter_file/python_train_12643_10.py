MOD = 1000000007
x, y = map(int, input().split())
li = [x, y, y-x, -x, -y, x-y]
n = int(input())
n %= 6
print(li[n] % MOD)
