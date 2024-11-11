l = int(input())

for _ in range(l):
    b = int(input())
    a = list(map(int, input().split()))
    m = max(a)
    f = True
    for n in a: 
        if m -n % 2 == 1:
            print("NO")
            f = False
            break
    if f:
        print("YES")