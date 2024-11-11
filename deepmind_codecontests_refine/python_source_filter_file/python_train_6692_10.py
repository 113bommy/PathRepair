n = int(input())
s = []
for i in range(n):
    a = int(input())
    l = len(str(a))
    k = a % 10
    s.append( (k - 1) * 10 + (l * (l + 1)) / 2)
for i in s:
    print(i)


