from sys import stdin

data = stdin.readlines()

remain = -10
invert = -20

m = [remain] * 10

for i, st in enumerate(data):
    if i == 0: continue
    op, x = st.strip().split()
    x = int(x)

    for j in range(10):
        bit = x % 2
        if op == '&' and bit == 0:
            m[j] = 0
        elif op == '|' and bit == 1:
            m[j] = 1
        elif op == '^' and bit == 1:
            if m[j] == 0:
                m[j] = 1
            elif m[j] == 1:
                m[j] = 0
            elif m[j] == remain:
                m[j] = invert
            elif m[j] == invert:
                m[j] = remain
        x = x // 2

print(3)
and_const = 0
for i, v in enumerate(m):
    if v != 0:
        and_const += 2**i

or_const = 0
for i, v in enumerate(m):
    if v == 1:
        or_const += 2**i

xor_const = 0
for i, v in enumerate(m):
    if v == invert:
        xor_const += 2**i

print('&', and_const)
print('|', or_const)
print('^', xor_const)