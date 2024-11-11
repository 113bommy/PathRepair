k = int(input())
l = int(input())
number = 0
while l%k==0:
    l = l//k
    number+=1
if l==1:
     print('YES')
     print(number)
else: print('NO')