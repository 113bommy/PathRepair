n,k=map(int,input().split())
a=list(map(int,input().split()))

ans_mono=0
ans_di=0
for i in range(n):
    for j in range(i+1,n):
        if a[i]>a[j]:ans_mono+=1
for i in range(n):
    for j in range(n):
        if a[i]>a[j]:ans_di+=1
print(int((ans_mono*k+ans_di*(k*(k-1)//2))%(1e+9+7)))
