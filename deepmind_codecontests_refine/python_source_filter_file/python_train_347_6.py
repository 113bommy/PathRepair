n=int(input())
l=[int(i) for i in input().split()]
if n==1 or n==2:
    print(-1)
    exit() 
if len(set(l))==1:
    print(-1)
    exit()
def rev(l):
    return all(l[i]>=l[i+1] for i in range(n-1))
def srt(l):
    return all(l[i]<=l[i+1] for i in range(n-1))
if rev(l) or srt(l):
    for i in range(1,n):
        if l[i]!=l[i-1]:
            print(i,i+1)
            exit()
f=0 
cnt=0
for i in range(1,n):
    if l[i]!=l[i-1]:
       if cnt==1:
           break 
       l[i],l[i-1]=l[i-1],l[i]
      # print(l)
       if srt(l) or rev(l):
           cnt+=1 
           l[i],l[i-1]=l[i-1],l[i]
       else:
           print(i,i+1)
           exit()
else:
    print(-1)