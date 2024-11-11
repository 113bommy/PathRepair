n=int(input())
h=list(map(int,input().split()))
cnt=0
a=0
for i in range(n-1):
    if h[i]>=h[i+1]:
    a+=1
    else:
        a=0
    cnt=max(cnt,a)
print(cnt)