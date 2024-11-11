n = int(input())
x = list(map(int, input().split()))
t = round(sum(x) / n)
p = 0
for i in x:
    p += ((i-t)**2)
print(p)