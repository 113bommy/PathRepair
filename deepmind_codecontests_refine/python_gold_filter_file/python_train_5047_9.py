x,y=[int(a) for a in input().split()]
if y==1:
    print(x)
    quit()
a=x
b=y
ans=0
while a > 0 and b > 0:
    if a >= b:
        ans = ans + a // b
        a = a % b
    else:
        ans = ans + b // a
        b = b % a
print(ans)