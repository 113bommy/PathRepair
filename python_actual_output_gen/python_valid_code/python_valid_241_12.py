n, l = map(int, input().split())

a = 0

for i in input().split():
    if i.count('4') + i.count('7') < l:
        a += 1
print(a)
