
m,n=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ar=0
br=0
for i in a:
    if(i%2==1):
        ar+=1
for j in b:
    if(j%2==0):
        br+=1

print((min(ar,br)+min(abs(m-ar),abs(n-br))))
