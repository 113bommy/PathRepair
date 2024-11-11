a1,a2,a3 = map(int,input().split())
b1,b2,b3 = map(int,input().split())
n = int(input())
a = a1+a2+a3
b = b1+b2+b3
shells = 0
if a%5 != 0:
    shells+=a//5+1
else:
    shells+=a//5
if b%10 != 0:
    shells+=b//10+1
else:
    shells+=b//10+1
#print(shells)
if shells<=n:
    print('YES')
else:
    print('NO')