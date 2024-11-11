k=int(input())
l=int(input())

ans=0
for x in range(1,33):
    if k**x==l:
        ans=x-1

if ans>0:
    print('YES')
    print(ans)
else:
    print('NO')
    
        
