a,b = map(int, input().split())
c = 0
while a < b:
    if str(a)[::-1] == str(a):
        c += 1
    a += 1
print(c)