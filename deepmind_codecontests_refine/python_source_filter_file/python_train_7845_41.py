a=int(input())
t=3
lst=[]
while 180*(t-2)/t<179:
    lst.append(180*(t-2)/t)
    t+=1
for i in range(a):
    s=int(input())
    if s in lst:
        print('YES')
    else:
        print('NO')
