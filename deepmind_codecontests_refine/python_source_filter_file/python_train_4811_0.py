n,k=map(int,input().split())
x=list(input())
ans=['0']*n
print(n)
for i in range(k):
    ans[i]=x[i]
    j=i+k
    while j < n:
        ans[j]=ans[j-k]
        j+=k
good=True
for i in range(n):
    if ans[i]>x[i]:
        break
    elif ans[i]<x[i]:
        good=False
        break
if good:
    print(''.join(ans))
    exit(0)
for i in range(k-1,-1,-1):
    if ans[k] != '9':
        ans[k] = chr(ord(ans[k])+1)
        for j in range(i+1,k):
            if ans[j] == '9':
                ans[j] = '0'
        break
for i in range(k):
    j=i+k
    while j<n:
        ans[j]=ans[j-k]
        j+=k
print(''.join(ans))