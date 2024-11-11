input()
a=b=1
for r in input().split():
    a*=b%(10**+7)
    if b*2<eval(r+'+2'):b+=1
print(a)