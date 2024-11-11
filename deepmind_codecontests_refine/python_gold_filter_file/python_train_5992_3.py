n = int(input())
a = [int(x) for x in input().split()]
s = sum(a)//(n/2)
i = done = 0
while done<n/2:    
    while a[i]==0:
        i += 1
    j = i+1
    while a[i]+a[j]!=s:
        #print("aa",i,j,a[i]+a[j])
        j += 1
    print(i+1,j+1)
    a[i] = a[j] = 0
    done += 1
