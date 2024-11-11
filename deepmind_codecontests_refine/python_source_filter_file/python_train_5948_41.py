n = int(input())
t = input()
i = 0
temp = n
l = []
while n:
    i += 1
    n -= i
    l.append(t[temp - n - 1])

print(''.join(l[::-1]))
