n, k = [int(i) for i in input().split()]
s = [int(i) for i in input().split()]
ans = 0
c = {}
c2 = {}
for i in s:
    if i in c:
        c[i]+=1
    else:
        c[i] = 1
    if i%(k) == 0:
        if i in c2:
            if i//k in c:
                c2[i]+=c[i//k]
        else:
            if i//k in c:
                c2[i]=c[i//k]
            else:
                c2[i]= 0
    if i%(k*k) == 0:
        if i//(k*k) == i//(k):
            ans+=(c[i//(k*k)]-1)*(c[i//(k*k)]-2)//2
        else:
            if i//k in c2:
                ans+=c2[i//k]
print(ans)
