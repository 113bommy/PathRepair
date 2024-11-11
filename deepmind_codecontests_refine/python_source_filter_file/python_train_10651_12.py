n=int(input())
taxi={}
pizza={}
girls={}
for l in range(n):
    m,name=input().split()
    taxi[name]=0
    pizza[name]=0
    girls[name]=0
    for o in range(int(m)):
        x=input()
        x=x.replace("-","")
        c=0
        v=x[0]
        for i in range(0,6):
            if x[i]!=v:
                c=1
        if c==0:
            taxi[name]+=1
            continue
        c=0
        for i in range(1,5):
            if x[i]>=x[i-1]:
                c=1
        if c==0:
            pizza[name]+=1
            continue
        girls[name]+=1
c=0
for i in taxi:
    if taxi[i]>c:
        c=taxi[i]
x=[]
print("If you want to call a taxi, you should call:",end=" ")
for i in taxi:
    if c==taxi[i]:
        x.append(i)
s=", ".join(x)
print(s+".")
c=0
for i in pizza:
    if pizza[i]>c:
        c=pizza[i]
x=[]
print("If you want to order a pizza, you should call:",end=" ")
for i in pizza:
    if c==pizza[i]:
        x.append(i)
s=", ".join(x)
print(s+".")
c=0
for i in girls:
    if girls[i]>c:
        c=girls[i]
x=[]
print("If you want to go to a cafe with a wonderful girl, you should call:",end=" ")
for i in girls:
    if c==girls[i]:
        x.append(i)
s=", ".join(x)
print(s+".")