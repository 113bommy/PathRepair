a,v=map(int,input().split())
b,w=map(int,input().split())
t=int(input())
if abs(b-a)/t<v-w:
    print('YES')
else:
    print('NO')