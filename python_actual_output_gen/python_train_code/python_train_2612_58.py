kol=int(input())
sp=list(map(int,input().split()))
chet=0
def sort(a):
    for j in range(len(a)-1):
        for i in range(len(a)-j-1):
            if a[i]>a[i+1]:
                a[i],a[i+1]=a[i+1],a[i]
sort(sp)
for a in range(kol-2):
    a1=sp[a]
    a2=sp[a+1]
    if a1+1!=a2:
        chet=chet+(a2-a1-1)
print(chet)