n=int(input())
s=''
if n>17*2:
    print(-1)
else:
    while n>0:
        if n>=2:
            s+='8'
            n-=2
        else:
            s+='9'
            n-=1
    print(s)
