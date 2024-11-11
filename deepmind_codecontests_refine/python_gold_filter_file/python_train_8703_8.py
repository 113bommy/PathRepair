l, r, x, y, k = [int(i) for i in input().split()]
for i in range(x, y+1) :
    if k*i <= r and k*i >= l :
        print("YES")
        exit(0)
print("NO")