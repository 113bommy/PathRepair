n,m=map(int,input().split())
s=set()
for i in range(n):
    s1=set(input().split()[1:])
    s=s|s1
print('YES'if len(s)==m else 'NO')