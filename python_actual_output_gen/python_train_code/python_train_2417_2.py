a=int(input())
i=1
ch=[]
while i<=a**0.5:
    if a%i==0:
        ch+=[i]
        ch+=[a//i]
    i+=1
ch=set(ch)
q={4,7,47,74,447,474,744,774,444,777}
if len(ch&q)>0:
    print('YES')
else:
    print('NO')