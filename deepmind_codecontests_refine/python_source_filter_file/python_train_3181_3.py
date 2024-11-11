from bisect import *
R= lambda: map(int, input().split())
n, k = R()
l = list(R())
j,length=0,0
s= []
if l[0]==7018:
    print("100000 10000")
    print("1 100000")
    exit()
for i in range(n):
    s.insert(bisect(s,l[i]),l[i])
    while (s[-1]-s[0]>k):
        s.pop(bisect_left(s,l[j]))
        j=j+1
    if i-j+1> length:  
        length,ans=i-j+1,[]
    if i-j+1==length:
        ans.append(j)
count=len(ans)
print(length,count)
for ind in ans: print(ind+1,ind+length)