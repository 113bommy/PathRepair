n=int(input())
s=input()
x=''
ind=0
incre=0
while True:
    x=s[ind]
    incre+=1
    ind=incre+ind
    if ind>n-1:
        break
print(x)