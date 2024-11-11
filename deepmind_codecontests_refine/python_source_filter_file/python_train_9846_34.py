x= int(input())
y = list(map(int, input().split()))
max = 0
r = 0
for q in range(x):
    if y[q] > max:
        max = y[q]
        r += y[q]
print((max*x)-r)