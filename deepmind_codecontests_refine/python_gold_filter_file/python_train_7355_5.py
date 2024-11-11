z = [int(s) for s in input().split()]
n = z[0]
a = z[1]
b = z[2]
st = 0
# print(n, a, b)
x = input()
f = []
for i in range(len(x)):
    f.append(x[i])
for i in range(len(f)):
    if i == 0 and f[i] == ".":
        if a >= b:
            f[i] = "a"
            a -= 1
        elif a < b:
            f[i] = "b"
            b -= 1
    
    elif f[i] == ".":
        if f[i-1] == "a":
            if b > 0:
                f[i] = "b"
                b -= 1
        if f[i-1] == "b":
            if a > 0:
                f[i] = "a"
                a -= 1
        if f[i-1] == "*" or f[i - 1] == ".":
            if a >= b and a > 0:
                f[i] = "a"
                a -= 1
            elif a < b and b > 0:
                f[i] = "b"
                b -= 1
for i in range(len(f)):
    if f[i] == "a" or f[i] == "b":
        st += 1
print(st)
