a = input()
a = a.split(' ')
a[0] = int(a[0])
a[1] = int(a[1])
n = 10**(a[0]-1)
n+= (n-n%a[1])
if len(str(n)) > a[0]:
    print(-1)
else:
    print(n)