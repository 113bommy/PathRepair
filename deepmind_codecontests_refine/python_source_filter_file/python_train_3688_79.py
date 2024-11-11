n = input()
d = list(map(int, input().split()))
a, b = list(map(int, input().split()))
d = [0, 0] + d
print(sum(d[a:b + 1]))
