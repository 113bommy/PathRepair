n = int(input())
a = int(input())
b = int(input())
c = int(input())
ans = 0
now = 'r'
for k in range(1, n):
    if(now=='r'):
        if(a>=b):
            ans += b
            now = 'E'
        elif(a<b):
            ans +=a
            now = 'O'
    elif(now=='O'):
        if(a>=c):
            ans +=c
            now = 'E'
        elif(a<c):
            ans+=a
            now = 'R'
    else:
        if(b>=c):
            ans+=c
            now = 'O'
        else:
            ans+=b
            now = 'R'
print(int(ans))