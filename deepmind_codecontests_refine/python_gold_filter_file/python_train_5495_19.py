k, n = map(int, input().split())
a = [int(i) for i in input().split(" ")]
d = [a[-1]-a[0]] + [k-(a[i]-a[i-1]) for i in range(1, n)]
print(min(d))