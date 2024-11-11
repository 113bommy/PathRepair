t = int(input())
for i in range(t):
    a = input()
    a = a.strip()
    a = a.split(' ')
    a = list(map(int, a))
    b = input()
    b = b.strip()
    b = b.split(' ')
    b = list(map(int, b))
    s = sum(b[1:])
    if s >= a[0] - b[0]:
        print(a[1])
    elif s < a[0] - b[0]:
        print(s)