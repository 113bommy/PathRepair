from math import ceil, log2

def is_one(a):
    return bin(a)[2:].count("1") == len(bin(a)[2:])

a = int(input())

is_one = lambda x: bin(x)[2:].count("1") == len(bin(x)[2:])
l = []
op_a = True
t = 0

while not is_one(a):
    t += 1
    if op_a:
        l.append(2 ** ceil(log2(a)) - 1)
        a = a ^ (2 ** ceil(log2(a)) - 1)
    else:
        a += 1
    op_a = not op_a

print(t)
for i in l:
    print(i, end=' ')