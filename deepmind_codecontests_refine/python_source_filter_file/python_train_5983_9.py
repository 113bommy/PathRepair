

n,p=map(int,input().split())
p=p-1
a=input()

fn=0 #fn+1=first non zero diff
ln=(n//2) #last non zero diff

sum_val=0
allzero=True
flag=True
for i in range(n//2):
    diff=abs(ord(a[i])-ord(a[n-i-1]))
    val=min(diff, 26-diff)
    sum_val+=val
    if val==0 and flag:
        fn+=1
    else:
        flag=False
    if val!=0:
        ln=i
        allzero=False
        


        
if p>n//2:
    p=(n-p-1)
if allzero:
    print(0)    
elif p>ln:
    print(sum_val+p-fn)
elif p<fn:
    print(sum_val+ln-p)
else:
    print(sum_val+min(ln-p,p-fn)+ln-fn)
        
    