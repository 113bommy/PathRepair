n=int(input().strip())
a=list(map(int,input().strip().split()))
hm={}
for i in range(len(a)):
    for j in range(i,len(a)):
        if a[i]+a[j] in hm:
            if i in hm[a[i]+a[j]] or j in hm[a[i]+a[j]]:
                continue
            else:
                print("YES")
                print(i+1, j+1, hm[a[i]+a[j]][0]+1, hm[a[i]+a[j]][1]+1)
                exit(0)
        else:
            hm[a[i]+a[j]] = [i,j]
print("NO")