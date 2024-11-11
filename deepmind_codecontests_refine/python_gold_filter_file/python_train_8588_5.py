n=int(input())
l=[]
for i in range(n):

    s=input()
    temp=s.split()
    temp1=[int(i) for i in temp]

    l.append(temp1)

l=sorted(l,key=lambda x:x[1])

cnt=1
prev=l[0][1]
for i in range(1,len(l)):

    if l[i][0]>prev:

        cnt=cnt+1
        prev=l[i][1]
print(cnt)

    
