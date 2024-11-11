n,k=map(int,input().split())
    
###########
s=[]
name=['']*n
ptr=0
yesno=[]
for i in range(26):
    s.append(str(chr(65+i)))
for i in range(26):
    s.append(str(chr(65+i))+'a')
###########

def f(x):
    global ptr
    global name
    for i in range(x,x+k):
        if(name[i]==''):
            name[i]=s[ptr]
            ptr=ptr+1

l=[]
yesno=list(input().split())

#print(yesno)
for i in range(n-k+1):
    if(yesno[i]=='YES'):
        f(i)
#print(name)

for i in range(n-k+1):
    if(yesno[i]=='NO' and i==0):
        f(i)
        name[i]=name[i+1]
    elif(yesno[i]=='NO'):
        name[i+k-1]=name[i]

        
for i in name:
    print(i," ",end='')
