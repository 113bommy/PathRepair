x=int(input())
f=int(input())
eyad=[]
w=[]
sol=0
for i in range(x):
    a=int(input())
    eyad.append(a)

w=sorted(eyad,reverse=True)
for i in range(x):
 if f-w[i]<0:
    sol+=1
    break

 if f-w[i]>0  :
        sol+=1
        f-=w[i]

print(sol)

