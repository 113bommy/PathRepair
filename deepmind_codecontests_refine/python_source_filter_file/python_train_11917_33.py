n=int(input())
a=0
l=[]
for i in range(1,n+1):
    a=a+i
    n=n-a
    if a==1:
        l.append(a)
        continue
    if n>0 and a>l[-1]:
        l.append(a)
    else:
        break
print(len(l))
