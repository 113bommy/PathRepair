n=int(input())
a=list(map(int,input().split()))
s,q,z=sum(a),0,0
for i in range(n-1):
    s-=i
    q+=i
    if s==q:z+=1
print(z)