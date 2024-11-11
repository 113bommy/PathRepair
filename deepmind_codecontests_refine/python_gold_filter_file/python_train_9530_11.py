k=0
for _ in range(int(input())):
    s=input()
    s=s.split()
    a=int(s[1])
    b=int(s[2])
    if a>=2400 and b>a:
        k=1
if k==1:
    print('YES')
else:
    print('NO')