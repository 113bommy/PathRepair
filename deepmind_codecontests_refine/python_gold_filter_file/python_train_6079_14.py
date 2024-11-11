n=input()
m=int(input())
y=[0]*(len(n))

for i in range (0,len(n)-1):
    if n[i]==n[i+1]:
        y[i+1]=y[i]+1
    else:
        y[i+1]=y[i]

for i in range (0,m):
    l,r=map(int,input().split())
    print(y[r-1]-y[l-1])


    