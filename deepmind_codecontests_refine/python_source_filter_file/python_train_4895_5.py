n=int(input())
R=[int(input()) for i in range(n)]
mini=10**9
maxi=-10**9
for r in R:
    maxi=max([maxi,r-mini])
    mini=min([mini,r])
print(maxi)
