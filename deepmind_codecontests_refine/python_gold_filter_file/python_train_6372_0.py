test=input()
wordlst=input()
word=input()
lst=word.split(" ")
ans=[]
ctr=0
for i in range(len(wordlst)):
    if wordlst[i] in lst:
        ctr+=1
    else:
        ans.append(ctr)
        ctr=0
ans.append(ctr)
sum=0
for i in ans:
    n=int(i*((i+1)/2))
    sum+=n
print(sum)
