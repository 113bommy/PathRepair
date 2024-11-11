
n=int(input())
left=0
right=0
for _ in range(n):
    a,b=map(int,input().split())
    if a>0:
        right+=1
    else:
        left+=1
if left!=right:
    print('Yes')
else:
    print('No')
