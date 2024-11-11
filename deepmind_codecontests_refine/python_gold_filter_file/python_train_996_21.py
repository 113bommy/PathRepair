a, b = tuple(map(int, input().split()))
c, d = tuple(map(int, input().split()))


from sys import exit

mod = d%c
for i in range(1000):
    if b >= d and b%c == mod:
        print(b)
        exit()
    b += a
print(-1)