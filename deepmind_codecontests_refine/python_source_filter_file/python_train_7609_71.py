n = int(input())
s = sorted(list(map(int, input().split())))
print(s[-1] - s[1] - n + 1)