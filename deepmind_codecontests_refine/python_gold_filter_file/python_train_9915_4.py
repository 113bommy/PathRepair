for _ in range(int(input())):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    a.append(a[-1])
    peak_n = 0
    for i in range(1,k-1):
        if(a[i-1]<a[i] and a[i]>a[i+1]):
            peak_n+=1
    l = 0
    peak_sol = peak_n
    for i in range(1,n-k+1):
        if a[i-1]<a[i] and a[i]>a[i+1]:
            peak_n-=1
        if a[i+k-3]<a[i+k-2] and a[i+k-2]>a[i+k-1]:
            peak_n+=1
        if peak_sol < peak_n:
            l=i
            peak_sol = peak_n
    print(peak_sol+1, l+1)