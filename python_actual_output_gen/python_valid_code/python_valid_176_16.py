x,y = map(int,input().split())
n = int(input())
a = [0] * (7)
a[0] = x
const = 1000000007
if (n == 1):
    print((x % const))
elif (n == 2):
    print((y % const))
else:
    a[1] = y
    a[2] = a[1] - a[0]
    for i in range(2,6):
        a[i+1] = a[i] - a[i-1]
    if (n > 6):
        print(((a[(n % 6) -1]) % const))
    else:
        print((a[n-1] % const))