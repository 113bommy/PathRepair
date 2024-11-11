k,s=map(int,input().split())
i=0
for x in range(k+1):
    for  y in range(k+1):
        if s-x-y<=k:
            i+=1
print(i)