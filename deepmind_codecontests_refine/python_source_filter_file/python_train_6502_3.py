n, m = list(map(int, input().strip().split(' ')))

def countFrend( r ):
    r = int(r)
    return int((r**2-r)/2)

d = n - m
iMax = countFrend(d + 1)

iMin = iMax
if m > 1:
    k = n % m
    j = n // m
    iMin = int(countFrend(j + 1)*k + countFrend(j)*(m-k))

print(str(iMin) + ' ' + str(iMax))