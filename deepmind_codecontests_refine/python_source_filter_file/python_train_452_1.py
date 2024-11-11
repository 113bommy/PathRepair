input();res=[0]*(10**6);ans=0;a=list(map(int,input().split()))
for i in a:res[bin(i).count('1')]+=1
for i in range(max(res)):ans+=res[i]*(res[i]-1)//2
print(ans)


