n=int(input())
flag=True
s=''
while n>0:
    if n>=2:
        s+='8'
        n-=2
    elif n==1:
        s+='4'
        n-=1
    if len(s)>20:
        print(-1)
        flag=False
        break
if flag:
    print(s)
    