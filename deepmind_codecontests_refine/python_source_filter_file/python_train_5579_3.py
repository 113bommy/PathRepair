import sys
input=sys.stdin.readline
I=lambda:list(map(int,input().split()))
a,b=I()
for tc in range(b):
    temp=list(I())[1::]
    s=set(map(abs,temp))
    if len(temp)==len(s):
        print('YES')
        sys.exit()
print('NO')