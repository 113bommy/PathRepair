n = int(input())
if n % 2 == 1:
    print("NO")
else:
    out = True
    a = [0] * n
    for i in range(n):
        a[i] = int(input())
    if len(set(a)) == 1 or len(set(a)) > 2:
        out = False
    if out and a.count(a[0]) != n//2:
        out = False
    if out == False:
        print("NO")
    else:
        print("YES")
        print(*set(a))