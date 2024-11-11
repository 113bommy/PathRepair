a,b=map(int,input().split())
ans=max(a,b)*2
print(ans if a!=b else ans-1)