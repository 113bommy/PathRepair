n=int(input());l=[int(i) for i in input().split()]
l.sort();s=0;k=0
for i in range(n):
    if i==0 or s<=l[i]:
        k+=1
        s+=l[i]
print(k)