def inp():
    return map(int, input().split())
q=int(input())
for i in range(q):
    n,a,b=inp()
    out=0
    if(b<=a*2):
        out=(n//2)*b+(n%2)*a
    else:
        out=n*a
    print(out)