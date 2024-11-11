n=int(input())
l=list(map(int,input().split()))
b=[];c1=0
for i in l:
    if i:b+=[-1];c1+=1
    else:b+=[1]
# print(l,b)
ma,pre=0,0
for i in range(n):
    pre=max(pre,0)
    pre+=b[i]
    ma=max(ma,pre)
print(c1+ma)