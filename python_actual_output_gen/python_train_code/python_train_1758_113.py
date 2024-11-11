a = list(map(int, input().split()))
a.sort()
print(sum(a)-min(a))