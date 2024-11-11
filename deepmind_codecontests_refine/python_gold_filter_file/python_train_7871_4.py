a, b = 0, 1023
n=int(input())
for i in range(n):
    cmd = input()
    c, x = cmd.split()
    x = int(x)
    if c == "|":
        a, b = a | x, b | x
    elif c == "&":
        a, b = a & x, b & x
    else:
        a, b = a ^ x, b ^ x
x = 0
y = 1023
z = 0
for i in range(10):
    a_i = (a >> i) & 1
    b_i = (b >> i) & 1
    if a_i and b_i:
        x |= 1 << i
    if (not a_i) and (not b_i):
        y ^= 1 << i
    if a_i and (not b_i):
        z ^= 1 << i
print("3\n| {}\n& {}\n^ {}".format(x, y, z))