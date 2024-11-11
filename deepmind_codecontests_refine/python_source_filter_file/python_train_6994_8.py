n=int(input())
c=[4,7,47,477,744]
a=0
for i in c:
    if (n%i!=0):
        a+=1
if (a==0):
    print('YES')
else:
    print('NO')