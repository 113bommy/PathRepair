n = int(input())

if n>36:
    print(-1)

else:
    s=''
    a = n//2
    s = s+'8'*a

    if(n%2==1):
        s+='0'

    print(s)