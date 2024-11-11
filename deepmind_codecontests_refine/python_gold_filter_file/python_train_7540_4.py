n = input()
a = list(map(int,input().split()))
l = sum(a)
h = maxh = minh = 1000
table = [[" "]*l for i in range(2001)]
k = 0
sign = 1
for i in a:
    if sign == 1:
        for j in range(i):
            table[h+j][k+j] = "/"
        maxh = max(maxh,h+(i-1))
        h += i-1
    else:
        for j in range(i):
            table[h-j][k+j] = "\\"
        minh = min(minh,h-(i-1))
        h -= i-1
    k += i
    sign *= -1
for i in range(maxh,minh-1,-1):
    print (''.join(table[i]))