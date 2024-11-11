n = int(input())
a = int(input())
b = int(input())
c = int(input())
if n<a and n<b:
    print(0)
else:
    if b-c<=a:
        x = b-c
    # t*x+b = n
        t = (n-b)//x
        t += 1
        n -= t*x
        print(t+n//a)
    else:
        print(n//a)