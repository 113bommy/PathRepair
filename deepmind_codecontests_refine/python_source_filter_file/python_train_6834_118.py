n = int(input())
if n==1:
    print('0')
elif n<=34:
    if n%2==0:
        print('8'*(n//2))
    else:
        print('8'*(n//2)+'0')
else:
    print(-1)