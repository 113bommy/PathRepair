a,v=map(int, input().split())
b,w=map(int, input().split())
t=int(input())

n=b-a
if n+(w-v)*t<0:
    print('YES')
else:
    print('NO')