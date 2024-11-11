st=input()
b=[]
for j in st:
    b.append(j)
n=len(b)
arr=[]
dp=[0]*(n)
j=0
while(j<n):
    if b[j]==")":
        if arr==[]:
            pass
        else:
            if arr[-1][0]==b[j]:
                pass
            else:
                p=arr.pop()
                dp[j] = j - p[1] + 1
                if (p[1]-1)>=0 and b[p[1]-1]==")":
                    dp[j]+=dp[p[1]-1]


    else:
        arr.append([b[j],j])
    j+=1
print(dp)
p=dp.count(max(dp))
if max(dp)==0:
    print(0, 1)
else:
    print(max(dp), p)




