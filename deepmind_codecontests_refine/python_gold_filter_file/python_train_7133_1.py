from functools import cmp_to_key

def c(x,y):
    if x+y > y+x:
        return 1
    else:
        return -1

n = int(input())
l = []

for _ in range(n):
    l.append(input())

l.sort(key = cmp_to_key(c))

print(''.join(l))
