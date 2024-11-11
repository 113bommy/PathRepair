l=[]
x=1
while(x<1e12):
    l.append(str(x))
    x*=2
t=int(input())
for _ in range(t):
    n=input()
    dis=100
    for i in range(len(l)):
        ans=0
        aux=0
        j=0
        while j<len(n):
            if aux>=len(l[i]):
                break
            if l[i][aux]==n[j]:
                aux+=1
            else: ans+=1
            j+=1
        if (aux>=len(l[i])):
            ans+=(len(n)-j+1)
        else:
            ans+=(len(l[i])-aux+1)
        dis=min(dis,ans)
    print(dis-1)