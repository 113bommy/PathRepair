x = int(input())
y = []

for i in range(x):
    y.append(list(map(int, input().split(" "))))

for i in range(x):
    if y[i][2] % 2 == 0:
        a = y[i][2]/2 * (y[i][0]-y[i][1])
        print(a)
    else:
        b = (y[i][2]//2)*y[i][0] - (y[i][2]//2)*y[i][1] + y[i][0]
        print(b)
