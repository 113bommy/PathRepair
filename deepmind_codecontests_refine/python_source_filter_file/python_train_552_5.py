n,k=map(int,input().split())
l=[]
for i in range(n):
    x,y=map(int,input().split())
    l.append((x,y))
l.sort(reverse=True)
print(l)
#r=l.index(k)
s=k-1
e=k-1
count=0
#print(l[e+1][1])
while(s!=-1 or e!=0):
    if s>=0:
        if l[s][0]==l[k-1][0] and l[s][1]==l[k-1][1]:
            count=count+1
            s=s-1
          #  print(s)
            if s<0:
                s=-1
        else:
            s=-1
    if e!=0:
        if l[e][0]==l[k-1][0] and l[e][1]==l[k-1][1]:
            count=count+1
            e=e+1
            if e>=n:
                e=0
        else:
            e=0
print(count-1)