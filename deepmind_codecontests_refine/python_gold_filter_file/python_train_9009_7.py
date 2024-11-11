n=int(input())
li=[int(input()) for x in range(n)]
li.sort()
li1=li[:]
li.sort(reverse=True)
ans=0 
for i in range(n):
        ans=ans+li[i]*li1[i]
        ans=ans%10007
print(ans)        
    