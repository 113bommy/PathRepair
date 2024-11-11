a=int(input())
z=[[0]+list(map(int,input().split())),[0]+list(map(int,input().split()))]
r=[0]+list(map(int,input().split()))
k=[]
for i in range(a,0,-1):
    k.insert(0,sum(z[0][:i])+r[i]+sum(z[1][i:]))
k1=[]
for i in range(1,a+1):
    k1.insert(0,r[i]+sum(z[0][:i])+sum(z[1][i:]))
s=a*100
k1=k1[::-1]
for i in range(a):
    for j in range(a):
        if i!=j:s=min(s,k[i]+k1[j])
print(s)