n,m,k=map(int,input().split())
for _ in range(2*k):
    a=list(map(int,input().split()))
ans=[]
for i in range(n-1):
    ans.append('U')
for i in range(m-1):
    ans.append('L')
if n==1:
    for i in range(m-1):
        ans.append('R')
elif m==1:
    for i in range(m-1):
        ans.append('D')
else:
    for i in range(n):
        for j in range(m):
            if i is n-1:
                if i%2==0:
                    for i in range(m-1):
                        ans.append('R')
                else:
                    for i in range(m-1):
                        ans.append('L')
            else:
                if i%2==0:
                    if j is  m-1:
                        ans.append('D')
                    else:
                        ans.append('R')
                else:
                    if j is  m-1:
                        ans.append('D')
                    else:
                        ans.append('L')
print(len(ans))
print("".join(map(str,ans)))