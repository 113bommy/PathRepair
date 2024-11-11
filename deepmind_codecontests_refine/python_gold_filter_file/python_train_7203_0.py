from sys import stdin, stdout
input = stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    l = list()
    for i in range(n):
        s = list(input())
        l.append((s.count('1'),s.count('0')))
    f,e,c = 0,0,0
    for i in range(n):
        f+=l[i][0]
        e+=l[i][1]
        if (l[i][0]+l[i][1])%2==0:
            c+=1
    if f%2==1 and e%2==1 and c==n:
        print(n-1)
    else:
        print(n)