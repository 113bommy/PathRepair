a = [int(z) for z in input().split()]
z = 0
z = sum(a)
if z % 2 == 1:
    print("NO")
    exit(0)
st = 0
for i in range(6):
    for j in range(i + 1, 6):
        for k in range(j + 1, 6):
            st = a[i] + a[j] + a[k]
            if z // 2 == st:
                print("YES")
                exit(0)
print("NO")