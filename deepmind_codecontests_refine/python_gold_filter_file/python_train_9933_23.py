n,k = map(int,input().split())
arr = list(map(int,input().split()))
pref = [0]+[0 for i in range(n)]
for i in range(1,n+1):
    pref[i]= arr[i-1] + pref[i-1]
m = 10**9
final=0
i=1
j=i+k-1
while i<=n and j<=n:
    if pref[j]-pref[i-1]<=m:
        final=i
        m =pref[j]-pref[i-1]
    i+=1
    j+=1
print(final)