t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    a = ""
    b = ""
    f = True
    for i in s:
        if f:
            if i=='2':
                a+='1'
                b+='1'
            elif i=='0':
                a+='0'
                b+='0'
            else:
                a+='1'
                b+='0'
                f=False
        else:
            a+='0'
            b+=i
    print(a)
    print(b)
            
