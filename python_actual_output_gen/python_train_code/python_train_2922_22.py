from math import ceil
n = int(input())
days, _ = map(int, input().split())
for i in range(n-1):
    a, d = map(int, input().split())
    days = a + ceil((days+1-a)/d)*d
print(days)