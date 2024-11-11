n=int(input())
m=0
a=[int(x) for x in input().split()]
s=input()
m=0
for  x in range(n-1):
    m=max(a[x],m)
    if s[x]=='0' and m>x+1:
        print('NO')
        quit()
print('YES')