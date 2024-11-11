n,t=map(int,input().split())
s=list(map(int,input().split()))
count=0
for i in range(t-1):
    if i==0:count+=s[0]-1
    if s[i]>s[i+1]:count+=n+s[i]-s[i+1]
    else:count+=s[i+1]-s[i]
print(count)