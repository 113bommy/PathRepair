n=int(input())
s=[]
for i in range(n):
    a=int(input())
    if 360%(180-a)==0 and a>=60 and a<=180:
        s.append('YES')
    else:
        s.append('NO')
for i in s:
    print(i)
