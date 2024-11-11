n=int(input())
R=[int(input()) for i in range(n)]
mini=10**9+1
maxi=-10**9-1
for r in R:
    maxi=max([maxi,r-mini])
    mini=min([mini,r])
print(maxi)
