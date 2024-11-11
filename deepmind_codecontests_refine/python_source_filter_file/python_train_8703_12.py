l, r, x, y, k = [int(i) for i in input().split()]
for i in range(l, r+1) :
    if k*i <= y and k*i >= x :
        print("YES")
        exit(0)
print("NO")
