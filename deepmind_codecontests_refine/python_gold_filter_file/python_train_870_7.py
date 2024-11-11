m=eval(input())
l=list(input().split(" "))
l= [int(i) for i in l]
N=eval(input())
for i in range(N):
    x,y=input().split(" ")
    x,y=int(x)-1,int(y)
    if x>0:
        l[x-1]+=y-1
    if x<m-1:
        l[x+1]+=l[x]-y
    l[x]=0
for i in l:
    print(i)