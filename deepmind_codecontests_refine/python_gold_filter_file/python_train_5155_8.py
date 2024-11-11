a,b=int(input()),list(map(int,input().split()))
d,s,c,e=0,0,b.index(min(b)),min(b)
for i in range(a):
    if b[i]==e:d=max(d,s);s=0
    else:s+=1
print(e*a+max(s+c,d))