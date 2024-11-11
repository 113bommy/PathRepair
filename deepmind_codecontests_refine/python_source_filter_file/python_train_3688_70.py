n = int(input())
di = list(map(int, input().split()))
a, b = map(int, input().split())
years = 0

for i in range(b - a):
	years += di[i]
print(years)