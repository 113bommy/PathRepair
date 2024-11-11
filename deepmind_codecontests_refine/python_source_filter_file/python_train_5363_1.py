n, p, q = map(int, input().split(" "))
s=input()

c=-1

for i in range (n):
    for j in range (n):
        if p*i+q*j==n:
            c=i
            d=j
            break
    if c!=-1:
        break

if c==-1:
    print(-1)
else:
    print(c+d)
    for i in range (c):
        print(s[p*i:p*(i+1)])
    e=c*p
    for j in range (d):
        print(s[e+q*j:e+q*(j+1)])
