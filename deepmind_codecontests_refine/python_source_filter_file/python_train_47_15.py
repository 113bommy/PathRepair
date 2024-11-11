n=int(input())
m=[]
j=2
c=0
for i in range(n):
    x,h=map(int,input().split())
    m.append([x,h])
if n==1:
    print(1)
else:
    for i in range(1,len(m)-1):
        x=m[i][0]
        h=m[i][1]
        a=x-m[i-1][0]-c
        b=m[i+1][0]-x
        if a<=h:
            if b>h:
                j+=1
                c=h
            else:
                c=0                 
        else:
            j+=1
            c=0
        print(j)