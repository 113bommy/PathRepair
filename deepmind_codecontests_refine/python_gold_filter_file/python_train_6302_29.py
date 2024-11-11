n = int(input())
s = ''
x = 1
while len(s) < n:
    s += str(x)
    x += 1
print(s[n-1])
