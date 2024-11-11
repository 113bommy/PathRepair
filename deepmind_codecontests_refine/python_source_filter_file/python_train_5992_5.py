n=int(input())
sp=input().split()
for i in range(0,len(sp)):
    sp[i]=(sp[i],i+1)
sp.sort(key=lambda x:x[0])
for i in range(0,n//2):
    print(int(sp[i][1]),int(sp[n-i-1][1]))