n = int(input())
for _ in range(n):
    a = input()[::-1]
    b = input()[::-1]
    l = 0
    for i in range(len(b)):
        if b[i] == '1':
            l = i
            break
    m = 0
    for i in range(l, len(a)):
        if a[i] == '1':
            m = i
            break
print(max(m-l,0))