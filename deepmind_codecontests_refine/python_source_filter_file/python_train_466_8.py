l=list(map(int,input().split()))
w=list(map(int,input().split()))
r=[500,1000,1500,2000,2500]
a,b=map(int,input().split())
k=0
for i in range(5) :
    k=k+max(0.3*l[i],(1-(l[i]/250))*r[i]-50*w[i])
k=k+a*100
k=k-b*50
print(int(k))
