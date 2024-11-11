n = int(input())
for i in range(n):
    k = input().split()
    l = int(k[1])
    f = int(k[2])
    if l < f and l >= 2400:
        print("YES")
        break
else:
    print("NO")