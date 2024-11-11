n=int(input())
a1=list(map(int,input().split()))
a2=list(map(int,input().split()))
ma,mi,last=max(a1[0],a2[0]),min(a1[0],a2[0]),0 if a1[0]>a2[0] else 1
a3=[]
for i in range(n):
    a3.append(a1[i])
    a3.append(a2[i])
for i in range(2,2*n):
    if i==2:
        a3[i]+=a3[1]
    elif i==3:
        a3[i]+=a3[0]
    
    elif i%2==0:
        a3[i]+=max(a3[i-1],a3[i-3])
    else:
        a3[i]+=max(a3[i-3],a3[i-5])
# print(a3)
print(max(a3[-1],a3[-2]))