w=str(input())
a=0
l=['H','Q','9','+']
for i in l:
    if w.find(i)!=-1:
        a=1
if a==1:
    print('YES')
else:
    print('NO')
