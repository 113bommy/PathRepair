a=[int(x) for x in input().split()]
ans=0
ans+=(2*a[0]+min(a[1],a[5]))*min(a[1],a[5])
ans+=(2*a[0]+2*min(a[1],a[5]))*(max(a[1],a[5])-min(a[1],a[5]))
ans+=(a[0]+min(a[1],a[5])+a[3])*(min(a[2],a[4]))
print(ans)
