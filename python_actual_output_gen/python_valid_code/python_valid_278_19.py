n = int(input())
l = list(map(int, input().split()))
sorted(l)
print(min(l[n-1] - l[1], l[n-2] - l[0]))