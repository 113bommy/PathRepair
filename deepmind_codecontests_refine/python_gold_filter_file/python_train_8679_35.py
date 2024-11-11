n = int(input())
a = list(map(int, input().split()))
z = 1
while True:
    if z in a:
        z += 1
        continue
    else:
        print(z)
        break
