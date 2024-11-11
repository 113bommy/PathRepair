n=int(input())
arr=list(map(int,input().split()));ans=1;c=1
for i in range(n-1):
 if 2*arr[i]>=arr[i+1]:c+=1
 else:c=1
 ans=max(c,ans)
print(ans)
