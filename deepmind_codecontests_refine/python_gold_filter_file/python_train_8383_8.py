[a,b] = map(int, input().split())
if b > a:
    print(b)
if b == a:
    print(2*b)
if b < a:
    x = a%b
    print(a+(b-x))