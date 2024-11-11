t=int(input())
for i in range(t):
    sr=input()
    b=sr.count('b')
    a=sr.count('a')
    c=sr.count('c')
    
    if b==a+c:
        print('YES')
    else:
        print('NO')
    