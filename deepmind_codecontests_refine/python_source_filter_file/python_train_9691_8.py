n, d = map(int, input().split())
x = [int(l) for l in input().split()]

k = 0
for i in range(len(x)):
    if i == 0:
        k += 1
    elif i == len(x) - 1:
        k += 1
    elif x[i+1] - x[i] > 2*d:
        k += 2
    elif x[i+1] - x[i] == 2*d:
        k += 1

print(k)