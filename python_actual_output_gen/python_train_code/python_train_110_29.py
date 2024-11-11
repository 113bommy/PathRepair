n,x,y=map(int,input().split())
a=input()
otv=0
b=[]
for i in range(n-1,n-x,-1):
    b.append(int(a[i]))
otv+=sum(b)
if b[y]==1:
    otv-=1
else:
    otv+=1
print(otv)


