from sys import stdin, stdout 
input = stdin.readline
 
a,b,k = map(int,input().split())

if k==0:
    s1 = '1'*b + '0'*a
    s2 = '1'*b + '0'*a
    a=0
    b=0
else:
    s1 = '1'
    s2 = '1'
    b-=1
    
    if a<k and a>0:
        # print(a,b,k)
        # print('AAA')
        s = '1'*(k-a) + '0'*(a-1)
        s1 += '1' + s + '0'
        s2 += '0' + s + '1'
        b -= ((k-a) + 1)
        a = 0
    else:
        s1 += '1' + ('0'*k)
        s2 += ('0'*k) + '1'
        b -= 1
        a -= k
    
    if b>0:
        s1 += '1'*b
        s2 += '1'*b
    if a>0:
        s1 += '0'*a
        s2 += '0'*a
# print(a,b)
if a<0 or b<0:
    print('NO')
else:
    print('YES')
    print(s1)
    print(s2)