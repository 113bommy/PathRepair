n=int(input()) 
l=[]
for i in range(n):
   l.append(int(input())) 
l.sort()
l1=l[::-1] 
ans=0
for i in range(n):
   ans+=l[i]*l1[i] 
print(ans%10007)
