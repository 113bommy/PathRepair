n,d=map(int,input().split())
q=int(input())

for i in range(q):
    x,y=map(int,input().split())
    if (d<=x+y<=2*n -d) and (-d<=x-y<=d):
        print('YES')
    else:
        print('NO')