n=int(input())
a_list=list(map(int,input().split()))
cnt = [0] * int(1e5 + 10)
sum=0
for i in a_list:
 cnt[i] +=1
 sum+=i
  
q=int(input())
ans=0
 
for j in range(q):
 x,y=map(int,input().split())
 sum+=(y-x)*cnt[x]
 cnt[x]+=cnt[y]
 cnt[y]=0
 print(sum)