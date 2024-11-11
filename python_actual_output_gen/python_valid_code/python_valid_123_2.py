x = int(input())

y = []
a = 0

for i in range(x):
    y.append(list(map(int, input().split(" "))))

z = int(input())-1

for i in y:
    if i[0] <= z <= i[1]:
        a += 1
    else:
        pass

print(x-a)
