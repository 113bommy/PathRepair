x = set([])
y = set([])
for i in range(1, int(input())):
    coordinates = input().split(' ')
    x.add(list(coordinates)[0])
    y.add(list(coordinates)[1])
print(min(len(set(x)), len(set(y))))
