def gcd(a,b):
    if a < b:
        a,b = b,a
    while(b != 0):
        a,b = b,a%b
    return a

n,m,q = map(int, input().split(" "))
hcf = gcd(n,m)
n = n//hcf
m = m//hcf
for ques in range(q):
    sx,sy,ex,ey = map(int, input().split(" "))
    sy -= 1
    ey -= 1
    if sx == 1:
        a = sy//n
    else:
        a = sy//m
    if ex == 1:
        b = sy//n
    else:
        b = sy//m
    if a == b:
        print("YES")
    else:
        print("NO")