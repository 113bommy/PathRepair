n,m = map(int,input().split())
count=0
for i in range(0,int(n**0.5)+1,1):
    if m==(n-i**2)**2+i:
        count=count+1
print(count)