a,v=map(int,input().split())
b,w=map(int,input().split())
t=int(input())
d=b-a
s=v-w
if d<s*t:
    print('YES')
else:
    print('NO')