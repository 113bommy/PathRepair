n = int(input())

a = [int(x) for x in input().split(' ')]

s = sum(a)

k = s % n

print(max(n - k, k))

