n,k=map(int,input().split())
s=input()
t=input()
res,tp=0,1
for i in range(n):
    tp*=2
    if s[i]=='b':
        tp-=1
    if t[i]=='a':
        tp-=1
    res+=min(tp,k)
    tp=min(tp,k)
print(res)