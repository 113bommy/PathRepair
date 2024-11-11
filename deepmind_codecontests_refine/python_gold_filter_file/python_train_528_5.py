def er(a, b, c):
    if (c < max(a, b)):
        return -1
    if ((a + b) % 2 == 1):
        return (c - 1) 
    if ((a + b) % 2 == 0):
        if ((a - c) % 2 == 0):
            return c
        else:
            return (c - 2)
a = int(input())
for i in range(a):
    s = input().split()
    print(er(int(s[0]), int(s[1]), int(s[2])))