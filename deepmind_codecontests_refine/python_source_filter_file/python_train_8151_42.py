n,k,l,c,d,p,nl,np = list(map(int,input().split()))

totalWater = k*l
totalLimes = c*d

toasts = totalWater//n
toasts = min(toasts,totalLimes)
toasts = min(toasts,p//np)
print(toasts//n)
