import bisect
n,m,v,p = map(int,input().split())
a = list(map(int,input().split()))
a = sorted(a)
wa = [a[0]]
for i in range(1,n):
    wa.append( wa[i-1] + a[i] )
border = a[n-p]
j = bisect.bisect_right(a,border)
for i in range(n-p):
    if a[i] + m >= border:
        if n-j+i+1 >= v:
            print(n-i)
            break
        else:
            if (j-i-1)*(a[i]+m)-(wa[j-1]-wa[i]) >= (v-(n-j+i+1))*m:
                print(n-i)
                break
