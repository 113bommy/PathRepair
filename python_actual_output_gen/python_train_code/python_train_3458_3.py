def sm(a, b):
    while b != 0:
        a, b = b, a % b
    return a

x, y, a, b = map(int, input().split())
z = x*y//sm(x, y)
r = (b-a)//z
if b%z == 0:
    r += 1
print(r)
