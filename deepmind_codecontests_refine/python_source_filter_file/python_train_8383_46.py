a = list(input().split(' '))
n = int(a[0])
k = int(a[1])
if (n > k):
    res = (n // k) * k
    print(res + k)
else :
    print(k)
