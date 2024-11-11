N = int(input())
a = list(map(int, input().split()))

ave = sum(a) / N

aa =[abs(a[i] - ave) for i in range(N)]

x = min(aa)

print(aa.find(x))