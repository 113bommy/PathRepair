s = input()
a,b,c = s.split(' ')
a = int(a)
b = int(b)
c = int(c)


def fast_pow(x, y):
    if (y == 0):
        return 1
    if (y % 2 == 1):
        return (fast_pow(x, y-1)*x) % 1000000007
    else:
        b = fast_pow(x, y/2) % 1000000007
        return (b*b)%1000000007

if(((a + b) % 2 == 1) & c == -1):
    print (0)
else:
    print(fast_pow(2, (b-1)*(a-1))% 1000000007)