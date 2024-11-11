N = int(input())
a = list(map(int, input().split())).sort()
print(a[-1]-a[0])