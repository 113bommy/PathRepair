s = [int(x) for x in input()]
p = len([x for x in s if  x % 2 == 0])
f = lambda ls: ''.join(str(x) for x in ls)
for i, x in enumerate(s):
    if x % 2 == 0:
        if x < s[-1]:
            print(f(s[:i]) + str(s[-1]) + f(s[i + 1:-1]) + str(x))
            break
        elif p > 1:
            p -= 1
        else:
            print(f(s[:i]) + str(s[-1]) + f(s[i + 1:-1]) + str(x))
            break
else:
    print(-1)
