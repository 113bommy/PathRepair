n = int(input())
ok = 0
for i in range(n):
    a, b, c = list(map(str, input().split()));
    if(int(c) > int(b) and int(b) >= 2400):
        ok = 1
if ok:
    print("YES")
else:
    print("NO")