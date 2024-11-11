s = input()

l = len(s)
a = (l + 19) // 20
b = (l + a - 1) // a
print (a, b)

x = a * b - l
k = 0
for i in range (a - x):
    print (s[k:k + b])
    k += b
for i in range (x):
    print (s[k:k + b - 1], end = '*')
    print ()
    k += b - i - 1