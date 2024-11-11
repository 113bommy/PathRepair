[a,b] = map(int, input().split())
if b > a:
    print(b)
if b == a:
    print(2*b)
else:
    x = a%b
    print(a+(b-x))