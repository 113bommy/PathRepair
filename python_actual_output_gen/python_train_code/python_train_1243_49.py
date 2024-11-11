n, x = map(int,input().split(' '))
n = int(n)
x = int(x)
icVal = x
dCount = 0

while n > 0:
    a, b = input().split(' ')
    b = int(b)
    if a == '-':
        b = b * -1
    if (icVal + b) > 0:
        icVal = icVal + b
    else:
        dCount = dCount + 1

    n = n - 1

print(str(icVal) + " " + str(dCount))
