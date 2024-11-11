n=int(input())
a=[4,7,44,47,74,77,444,447,474,477,744,747,774,777]
flag=0
for i in a:
    if n%i==0:
        flag==1
if flag==0:
    print('NO')
else:
    print('YES')