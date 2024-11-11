k = int(input())
l = int(input())
c = -1
while(l%k==0):
    l /=k
    c+=1
   
if c>=0 and l==1:
    print('YES')
    print(c)
else:
    print('NO')

