n=int(input())
lst=[]
d=[False for I in range(55556)]
for i in range(2,55555):
    if d[i]==False:
        lst.append(i)
        for j in range(i,55555,i):
            d[j]=True
ans=[]
for i in lst:
    if i%5==1:
        ans.append(i)
print(ans[:n])