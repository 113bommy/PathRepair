n=int(input())
a=list(map(int,input().split()))
m=int(input())
b=list(map(int,input().split()))
sorted(a)
sorted(b)
indexa=[]
indexb=[]
ans=0
for i in range(len(a)):
    for j in range(len(b)):
        if abs(a[i]-b[j])<=1 and i not in indexa and j not in indexb:
            ans+=1
            indexa.append(i)
            indexb.append(j)
            break
print(ans)