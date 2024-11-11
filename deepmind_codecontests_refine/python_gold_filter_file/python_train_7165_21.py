n=int(input())
a=list(map(int, input().split()))
b=list(map(int, input().split()))
s,t=0,0
for i,j in zip(a,b):
    if i>j:t+=i-j
    else:s+=(j-i)//2
if s>=t:print('Yes')
else:print('No')