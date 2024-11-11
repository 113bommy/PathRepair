c={"0":6,"1":2,"2":5,"3":5,"4":4,"5":5,"6":6,"7":4,"8":7,"9":6}

a,b=map(int,input().split())
ans=0
for i in range(a,b+1):
    for j in str(i):
        ans+=c[j]
print(ans)