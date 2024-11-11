n=int(input())
j=n
l=[]
while int(n)>0:
    t=input().split()
    l.append(int(t[0]))
    t=[]
    n=n-1
c=int(input())
i=0
index=0
while i<j:
    if c<l[i]:
        index=i-1
        break
    else :
        i=i+1   
print(j-index)
