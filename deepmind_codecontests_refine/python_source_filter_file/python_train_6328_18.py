n=int(input())
D={}
for i in range(n):
    s=(str(i)[0],str(i)[-1])
    if s in D:
        D[s]+=1
    else:
        D[s]=1
ans=0
for i in D:
    t=(i[1],i[0])
    if t in D:
        ans+=D[t]*D[i]
print(ans)
