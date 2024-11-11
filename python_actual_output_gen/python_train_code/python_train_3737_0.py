c=0
n=int(input())
maxx=0
f=[]
curren={}
special=[]
for i in range(n):
    x=input().split()
    if x[0]=='+':
        f.append(x[1])
        c+=1
    else:
        if x[1] in f:
            c-=1
            f.remove(x[1])
        else:
            special.append(i)
    curren[i]=c

count=len(special)
i=0
j=0
while i<n and j<len(special):
    while i<special[j]:
        curren[i]+=count
        i+=1
    count-=1
    j+=1
maxx=max(curren.values())
print(maxx)
