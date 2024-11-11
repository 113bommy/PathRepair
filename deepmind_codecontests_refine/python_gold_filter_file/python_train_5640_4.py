from sys import stdin
input=stdin.readline
n=int(input())
a=[[] for i in range(n)]
for i in range(n-1):
    c,d=map(int,input().split())
    a[c-1].append(d-1)
    a[d-1].append(c-1)
if n==2:
    print('YES')
else:
    k=0
    for i in a:
        if len(i)==2:
            exit(print('NO'))
    print('YES')
