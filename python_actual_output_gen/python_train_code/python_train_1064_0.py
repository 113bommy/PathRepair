a=[]
n=int(input())
k=0
for i in range(0,n):
    s=str(input())
    s=s.replace(' ','')
    for b in range(0,len(a)):
        if a[b]==s:
            k=k+1
    if k==0:
        a.append(s)
    else:
        k=0
print(len(a))
