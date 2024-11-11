t=int(input())
for i in range(t):
    a, b, c = map(str, input().split())
    b = int(b)
    c = int(c)
    if b >= 2400 and c > b:
        print("YES")
        break
print("NO")
