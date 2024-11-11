a,b=map(int,input().split())
ans=max(a,b)*2
print(ans-1 if a!=b else ans)