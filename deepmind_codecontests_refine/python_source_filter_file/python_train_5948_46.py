a = input()
b = ''
if len(a) % 2 == 0:
    for i in range(len(a) // 2):
        b += a[-i - 1] 
        b += a[i]
    for i in range(len(a)):
        print(b[- i - 1], end = '')
else:
    for i in range(len(a) // 2):
        b += a[-i - 1] 
        b += a[i]
    b += a[len(a) // 2]
    for i in range(len(a)):
        print(b[- i - 1], end = '')    