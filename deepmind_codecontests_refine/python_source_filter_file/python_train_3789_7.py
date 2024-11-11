n, m = map(int, input().split())
a = [int(i) for i in input().split()]
add = [0] * n
b = 0
results = []
for i in range(m):
    op = [int(j) for j in input().split()]
    if (op[0] == 1):
        add[op[1] - 1] = op[2] - a[op[1] - 1]
    elif (op[0] == 2):
        b += op[1]
    else:
        results.append(a[op[1] - 1] + add[op[1] - 1] + b)
for result in results:
    print (result)