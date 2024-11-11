IL = lambda: list(map(int, input().split()))
I = lambda: int(input())

n = I()
a = [i%2 for i in IL()]
ans = a[0] == a[-1] == 1
parity = 0
count = 0
for i, el in enumerate(a):
    parity += 1
    if el and parity%2 and (i==n-1 or a[i+1]):
        count += 1
        parity = 0

if parity%2:
    ans = False
ans = ans and count%2

print("Yes" if ans else "No")