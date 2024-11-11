fnf = list(map(int,input().split()))
lit=0
for i in range(fnf[0]):
    a = list(map(int,input().split()))
    for j in range(fnf[1]):
        k=j+1
        if a[2*k-1]==0 or a[2*k-2]==0:
            lit+=1
print(lit)