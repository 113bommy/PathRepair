n = int(input())
l = list(map(int, input().split()))
s = 0
d = 0
i = 0
j = n-1
c = 0
while i<=j:
    if c % 2 == 0:
        if l[i] > l[j]:
            s += l[i]
            i+=1
        else:
            s += l[j]
            j-=1
    else:
        if l[i] > l[j]:
            d += l[i]
            i+=1
        else:
            d += l[j]
            j-=1
    c+=1
print(s,d)