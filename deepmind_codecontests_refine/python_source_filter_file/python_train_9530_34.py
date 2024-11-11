n = int(input())
ok = 0
for i in range(n):
    a, b, c = list(map(str, input().split()));
    if(int(b) > int(c) and int(b) >= 2400):
        ok = 1
if ok:
    print("YES")
else:
    print("NO")