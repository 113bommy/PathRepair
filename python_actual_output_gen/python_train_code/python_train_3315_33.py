n=int(input())
a=[int(x) for x in input().split(' ')]
i=0
while i<n:
    flag=0;r=a[i];
    l=a[:i];m=a[i+1:]
    for j in l:
        if abs(r-j)%2==0:
            flag==1
            break
    if flag==1:
        i+=1
        continue
    else:
        for j in m:
            if abs(r-j)%2==0:
                flag=2
                break
    if flag!=2:
        print(i+1)
        break
    i+=1