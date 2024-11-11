n = int(input())
a = list(map(int, input().split()))
z = 1
for i in a:
    if z in a:
        z += 1
        continue
    else:
        print(z)
        break
