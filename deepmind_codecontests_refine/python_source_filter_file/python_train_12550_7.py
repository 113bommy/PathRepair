n,c=map(int,input().split())
l=list(map(int,input().split()))
x=0
for i in range(n-1):
    if l[i+1]-l[i] > c:
        x=1
    else:
        x+=1
print(x)