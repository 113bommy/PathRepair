n,k=map(int,input().split())
s=input()
c=list(input().split())
a=[]
i=0
while(i<n):
    x=""
    while(i<n):
        if(s[i] in c):
            x=x+s[i]
        else:
            a.append(x)
            break
        i+=1
        if(i==n):
            a.append(x)
    i+=1
count=0
print(a)
for i in range(len(a)):
    count=count+len(a[i])*(len(a[i])+1)/2
print(int(count))
                   