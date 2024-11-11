n, k = map(int, input().split(' '))
l = (n-1)//(2*k+1)+1
x = l*(2*k+1)-n
a = min(n, k, x)
if n<2*k+1:
    print(1)
    print(n)
else:
    print(l)
    for i in range(l):
        print(k+1+i*(2*k+1)-a,end=' ')