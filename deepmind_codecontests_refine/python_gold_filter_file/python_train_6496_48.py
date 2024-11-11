q=input().split(" ")
n=int(q[0])
m=int(q[1])
q=input().split(" ")
a=1
total=0
for i in range(0,m) :
    if int(q[i])>=a :
        total=total+int(q[i])-a
        a=int(q[i])
    else :
        total=total+n-a+1
        a=1
        total=total+int(q[i])-a
        a=int(q[i])
print(total)
