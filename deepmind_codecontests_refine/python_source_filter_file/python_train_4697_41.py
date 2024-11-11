a, b ,c =map(int,input().split())
t = 0
if a+b>c:
    t = 0
else:
    t = t+c-a-b
if b+c>a:
    t = t + 0
else:
    t = t+ a-b-c
if a+c>b:
    t = t + 0
else:
    t = t+ b - a-c
print(t)

