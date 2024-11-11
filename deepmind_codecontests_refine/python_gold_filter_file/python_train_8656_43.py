n=int(input())
for i in range(n):
    t=int(input())
    s=input()
    c=-1
    for j in range(t):
        if(s[j]=='8'):
            c=j
            break
    if(c==-1 or t-c<11):
        print('NO')
    else:
        print('YES')
