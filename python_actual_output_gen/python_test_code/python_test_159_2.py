n,a,s=int(input()),list(map(int,input().split())),10**9
for i in range(n):s=min(s,a[i]/(max(n-i-1,i)))
print(s)