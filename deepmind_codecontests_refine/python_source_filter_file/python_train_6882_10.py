def s(a,b):
    ss = 0
    while a!=0:
        ss = a%10 + b%10 + ss
        a=a//10
        b=b//10
    return ss

n = int(input())
if len(str(n)) == 1:
    print(n)
else:
    a = int(str((int(str(n)[0]) - 1))+'9'*len(str(n)[1:]))
    b = n-a 
    print(s(a,b))
