n = int(input())
m=int(input())

div = 1
while div <= m and n > 0:
    div *= 2
    n -= 1
if div > m:
    print(m)
else:
    print(m%div)