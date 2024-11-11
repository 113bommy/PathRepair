n = int(input())
x = list(map(int, input().split())

res = 0
r = round(sum(x)/len(x))
for i in x:
    res +=(i-p)**2
print(res)