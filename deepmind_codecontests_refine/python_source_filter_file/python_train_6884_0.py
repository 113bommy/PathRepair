s=input()
a=[]
for i in s:
    if(i in ['[',']',':','|']):
        a.append(i)
fb=-1;fc=-1;sc=-1;sb=-1;
#print(a)
for i in range(len(a)):
    if(a[i]=='['):
        fb=i
        for j in range(i+1,len(a)):
            if(a[j]==':'):
               fc=j
               break
        break
for i in range(len(a)-1,fc,-1):
    if(a[i]==']'):
        sb=i
        for j in range(sb-1,fc,-1):
            if(a[j]==':'):
               sc=j
               break
        break
#print(fb,fc,sb,sc)
cnt=0
for i in range(fc+1,fb):
    if(a[i]=='|'):
        cnt+=1
if(fb==-1 or fc==-1 or sc==-1 or sb==-1):
    print(-1)
else:
    print(cnt+4)       