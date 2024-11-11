n, t = map(int, input().split())
xs = list(input())
dot = xs.index('.')

pos = -1
for i in range(dot+1, n):
    if xs[i] > '4':
        pos = i
        break

if pos < 0:
    print("".join(xs))
else:
    for j in range(t):
        if xs[pos-1-j] != '4':
            break
    pos = pos - 1 - j
    while pos >= 0 and (xs[pos] == '9' or pos == dot):
        pos -= 1

    if pos < 0:
        print("1", end="")
        print("0"*dot)
    elif pos < dot:
        print("".join(xs[:pos]), end="")
        print(chr(ord(xs[pos])+1), end="")
        print("0"*(dot-pos-1))
    else:
        print("".join(xs[:pos]), end="")
        print(chr(ord(xs[pos])+1))
