n=int(input())
s=0
for i in range(1,n+1):
    x,y=(int(i) for i in input().split())
    if x+2<y:
        s=s+1
print(s)
        
