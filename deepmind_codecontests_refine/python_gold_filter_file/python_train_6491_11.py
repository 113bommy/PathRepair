a,b=map(int,input().split())
#print(len(str(a)))
t=a
s=a
a=str(s)
p=t
for i in range(len(a)-1,0,-1):
    if a[i]=='9':
        continue
    else:
        x=9-int(a[i])
        s=s-10**(len(a)-i)+x*10**(len(a)-i-1)
    #print(s,t-s,p,a)
    if t-s>b:
        print(a)
        exit()
    p=a   
    a=str(s)
    #break
print(s)  
    

    