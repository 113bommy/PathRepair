k = int(input())
i = k
j=0
a=[""]*18
if k>36:
    print(-1)
else:
    while i>1:
        a[j]="8"
        j+=1
        i-=2
    if i==1:
        a[j]="4"
    print("".join(a))