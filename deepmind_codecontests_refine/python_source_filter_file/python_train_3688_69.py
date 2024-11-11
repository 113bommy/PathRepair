n = int(input())
di = list(map(int, input().split()))
a, b = map(int, input().split())
years = 0

for i in range(a - 1, b - a):
	years += di[i]
print(years)