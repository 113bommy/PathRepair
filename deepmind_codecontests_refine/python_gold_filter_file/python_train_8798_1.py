n=int(input())
d=dict()
for i in range(n):
    s=input()
    b=(n-i)%200
    a=(n-i)//200
    d[s]=((a*'È')+chr(b))
d1=sorted(d.items(),key=lambda d:d[1])
l=len(d1)
for i in range(l):
    print(d1[i][0])