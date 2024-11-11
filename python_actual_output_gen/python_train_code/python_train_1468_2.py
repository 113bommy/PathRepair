a=[1]
c={1:0}
n=int(input())
b=list(map(int,input().split()))
j=1
for i in range(n):
    if b[i]==0:
        a.append(j)
        c[j]=i+1
    elif b[i]==c[a[b[i]]]:
        a.append(a[b[i]])
        c[a[b[i]]]=i-1
        j-=1
    else:
        a.append(j)
        c[j] = i + 1
    j+=1
print(j-1)