n=int(input())
arr=list(map(int,input().split()));ans=0;c=1
for i in range(n-1):
 if 2*arr[i]>=arr[i+1]:c+=1
 else:ans=max(c,ans);c=1
print(ans)
