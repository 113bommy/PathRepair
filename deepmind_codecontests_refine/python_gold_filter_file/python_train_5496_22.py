n = int(input())
d, c = 0, 0

for i in range(n):
    p, q = map(int, input().split())
    d = d + q
    c = c + p*q

print((d-1)+(c-1)//9)