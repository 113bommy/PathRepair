n,k = input().split()
mn = 0
n,k = int(n),int(k)
if k>0 : mn = 1
mx = min(k*2,n-k)
print(mn,mx)