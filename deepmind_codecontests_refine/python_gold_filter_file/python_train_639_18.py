n,m,k=map(int,input().split())
spitem=list(map(int,input().split()))
s=1
ans=1
c=0
pg=(spitem[0] - s) // k


for i in range(len(spitem)):
    if (spitem[i]-s) // k ==pg:
        c+=1
    else:
        #print(i,'hii')
        ans+=1
        s+=c
        c=1
        pg=(spitem[i]-s)//k
print(ans)
