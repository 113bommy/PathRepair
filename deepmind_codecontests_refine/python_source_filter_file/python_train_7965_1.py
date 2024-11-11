n=int(input())
a=list(map(int,input().split()))
s=input()
s=list(s)
sum_a=[0]
sum_b=[0]
for i in range(n):
    if i!=0:
        sum_a.append(sum_a[-1])
        sum_b.append(sum_b[-1])  
        
    
    if s[i]=='A':
        sum_a[-1]+=a[i]
    else:
        sum_b[-1]+=a[i]
aa=sum_b[-1]-sum_a[-1]
ans=[]
for i in range(n):
    ans.append(sum_b[-1]-sum_b[i]+sum_a[i])
s.reverse()
a.reverse()

sum_a=[0]
sum_b=[0]
for i in range(n):
    if i!=0:
        sum_a.append(sum_a[-1])
        sum_b.append(sum_b[-1])  
        
    
    if s[i]=='A':
        sum_a[-1]+=a[i]
    else:
        sum_b[-1]+=a[i]
for i in range(n):
    ans.append(sum_b[-1]-sum_b[i]+sum_a[i])
print(max(max(ans),aa))

   