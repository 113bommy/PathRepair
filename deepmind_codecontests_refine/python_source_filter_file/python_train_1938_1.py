stroka=input()
k=''
for i in range(0,len(stroka)):
    if stroka[i]==' ':
        R=int(k)
        k=''
    else:
        k+=stroka[i]
d=int(k)
n=int(input())
x=[]
y=[]
r=[]
answer=0
for i in range(0,n):
    stroka=input()
    k=''
    count=1
    for i in range(0,len(stroka)):
        if stroka[i]==' ':
            if count==1:
                x.append(int(k))
            else:
                y.append(int(k))
            count+=1
            k=''
        else:
            k+=stroka[i]
    r.append(int(k))
for i in range(0,n):
    line=(x[i]**2+y[i]**2)**0.5
    if (line-r[i]>=d)and(line+r[i]<=R):
        answer+=1
print(answer)
