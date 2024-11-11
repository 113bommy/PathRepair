n = int(input())
a = [int(x) for x in input().split()]
for i in range(n):
    mini = 0
    maxi = 0
    if i>0 and i>=n-1:
        mini = abs(a[i]-a[i-1])
        maxi = abs(a[i]-a[0])
    elif i<n-1 and i<=0:
        mini =abs(a[i]-a[i+1])
        maxi =abs(a[i]-a[-1])
    else:
        mini = min(abs(a[i]-a[i-1]),   abs(a[i]-a[0]))
        maxi = max( abs(a[i]-a[0]), abs(a[i]-a[-1]))
    print(mini,maxi)