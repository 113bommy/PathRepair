n = int(input())
m = sorted(list(map(int, input().split())))
print(m[-1] - m[0] - n + 1)