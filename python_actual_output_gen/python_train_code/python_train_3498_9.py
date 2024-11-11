
p,y = map(int, input().split())

for x in range(y, p, -1):
    if all(x%i for i in range(2,min(x, int(y**0.5))+1)):
        print(x)
        exit()

print (-1)