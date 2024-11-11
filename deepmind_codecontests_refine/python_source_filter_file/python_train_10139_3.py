a,b=list(map(int,input().split()))
k=a//b
w=[]
for i in range(b):
    w.append(a//b)
    a-=(a//b)
    b-=1
print(w)
