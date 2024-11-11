n=int(input())
a=list(map(int,input().split()))
h=[0]
j=[0]
for i in range(n):
    if a[i]>500000:
        j.append(1000000-a[i])
    else:
        h.append(a[i])
if max(h)<max(j)+1:
    print(max(j))
else:
    print(max(h)-1)
