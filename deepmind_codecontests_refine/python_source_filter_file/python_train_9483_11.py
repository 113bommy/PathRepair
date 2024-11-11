R=lambda:map(int,input().split())
R()
c,a=R(),[*R()]+[0]
i=0
for x in c:i+=x<=a[i]
print