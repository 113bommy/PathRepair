#n = int(input())
n, m, k = map(int, input().split())
h, d = map(int, input().split())
#s = input()
#c = list(map(int, input().split()))
a = []
l = 0
while h > 0:
    if n > d or h < m:
        h -= m
        a.append('STRIKE')
    else:
        n += k
        a.append('HEAL')
    l += 1
    n -= d
print(l)
print('\n'.join(a))
    