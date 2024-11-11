s = input()
t = input()

a = list(s)
b = ''.join(a[::-1])

if b == t:
    print("YES")
else:
    print("NO")