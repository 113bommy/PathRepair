N = int(input())
lst = list(map(int, input().split()))
avg = round(sum(lst) // N)

result = 0
for i in lst:
    result += (i - avg)**2

print(result)
