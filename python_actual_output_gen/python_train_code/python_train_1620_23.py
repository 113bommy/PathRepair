a,b= map(int, input().split())
n=0
if a<4:
    n=300000-(a-1)*100000
if b<4:
    n=n+300000-(b-1)*100000
if a==1&b==1:
    n=1000000
print(int(n))