n,k=map(int,input().split());A=list(map(int,input().split()));B=A.copy();B.sort(reverse=True)
t=B[:k];Ans=[];d={}
for i in range(n):d[A[i]]=i
for i in t:Ans.append(d[i])
Ans.sort();m=1
for i in range(1,len(Ans)):m*=Ans[i]-Ans[i-1]
print(sum(t),m%998284353)
