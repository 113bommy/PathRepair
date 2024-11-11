n = int(input())
s = [int(i) for i in input().split()]
print(max([s[:i].count(1) + s[i:].count(0) for i in range(len(s) + 1)]))