n,a,b=map(int,input().split())
l=list(map(int,input().split()))
out=[]
for i in range(n):
    out.append(str(l[i]*a%b//a))
print(' '.join(out))