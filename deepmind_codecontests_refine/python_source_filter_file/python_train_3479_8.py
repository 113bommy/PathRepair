a=int(input())
b=list(map(int,input().split()))

dic={}
for i in b:
    try:
        dic[i]+=1
    except:
        dic[i]=1

t=sorted(dic.keys())
tt=len(t)

r=0
s=[]
for i in range(tt-1):
    s.append(t[i])
    dic[t[i]]-=1
    r+=1
s.append(t[-1])
r+=1
for i in range(2,tt+1):
    i*=-1

    if dic[t[i]] == 1:
        s.append(t[i])
        r+=1


print(r)
print(*s)