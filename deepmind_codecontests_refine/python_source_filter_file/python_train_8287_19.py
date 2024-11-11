n = int(input())
a = int(input())
b = int(input())
c = int(input())
l = min(a, b, c)
if (n == 1):
    print (min(a, b))
elif (l != c):
    print ((n-1)*l)
else:
    print ((n-2)*l + min(a, b))
