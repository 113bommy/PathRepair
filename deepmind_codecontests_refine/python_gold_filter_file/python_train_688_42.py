n=int(input())
s=['o']*2000
a,b=1,1
while a<1000:
    s[a]='O'
    a,b=b,a+b
print(''.join(s[1:n+1]))