a,b=map(int,input().split())
l=list(map(int,input().split()))
t=sum(l)/(4*b)
ans = [i for i in l if i>t]
print('Yes' if len(ans)>=b else 'No')