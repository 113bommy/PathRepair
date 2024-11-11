n=input()
m=input()
lst=list(n)
lst.sort()
i=0
while(i<len(n) and lst[i]=='0'):
    i+=1
if(i<len(n)):
    t=lst[i]
    lst[i]=lst[0]
    lst[0]=t
n=''.join(lst)
if n==m:
    print("OK")
else:
    print("WRONG ANSWER")