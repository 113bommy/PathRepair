n,k=map(int,input().split())
dic={}
for i in range(n):
    a,b=map(int,input().split())
    c=a*100+(51-b)
    if c in dic:
        dic[c]+=1
    else:
        dic[c]=1
count=0
r=sorted(dic.keys())
r.reverse()
for i in r:
    if count+dic[i]>=k:
        print(dic[i])
        break
    else:
        count+=dic[i]