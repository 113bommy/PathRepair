a = int(input())
g = 0
for i in range(a):
    n, b, d = [i for i in input().split()]
    if int(b) >= 2400 and int(d)-int(b)>=1:
        g += 1
if g > 0:
    print("YES")
else:
    print("NO")
