n=int(input())
a,b=input().split()
a,b=int(a),int(b)
z=[0]*100
for i in range(n-1):
    S,E=input().split()
    for i in range(int(S),int(E)):
        z[i]=1
#print(z)
print((b-a)-z[a:b+1].count(1)+1)