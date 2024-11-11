def op():
    keyboard = list(input())
    s = list(input())
    p = keyboard.index(s[0])
    o = 0
    for i in range(len(s)):
        o += abs(keyboard.index(s[i])-p)
        p = keyboard.index(s[i])
    return o
for i in range(int(input())):
    op()