
m,n=list(map(int,input().strip().split(' ')))
s=input()
t=input()
MIN=len(s)
index=-1
for i in range(0,len(t)-len(s)+1):
    count=0
    for j in range(i,i+len(s)):
        if s[j-i]!=t[j]:
            count+=1
    if count<MIN:
        MIN=count
        index=i
ANS=[]
for j in range(index,index+len(s)):
    if s[j-index]!=t[j]:
        ANS+=[j-index+1]
print(MIN)
print(*ANS)
        