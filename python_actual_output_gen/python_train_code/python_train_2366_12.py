n = int(input())

name = ''
Max = 0
for i in range(n):
    data = input().split()
    handle = data[0]
    data = list(map(int,data[1:]))
    data[0] = data[0] * 100
    data[1] = data[1] * -50
    if sum(data) > Max or Max == 0:
        Max = sum(data)
        name = handle

print(name)
