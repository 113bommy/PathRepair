def a(n):
    a = list()
    b = list()
    for i in range(1,n+1):
        if i%2==0:
            a.append(i)
        else:
            b.append(i)
    if not sum(a)==sum(b):
        b[-1]=sum(a)-sum(b[:-1])
    return a+b

def check(n):
    if n==2 or (n//2)%2!=0:
        return False
    else:
        return True

t = int(input())
for i in range(t):
    n = int(input())
    if check(n):
        print("YES")
        print(a(n))
    else:
        print("NO")