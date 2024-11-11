n=int(input())
a=list(map(int,input().split()))
a1=[]
for i in range(n-1,-1,-2):
    a1.append(a[i])
a2=[]
for i in range(n-2,-1,-2):
    a2.append(a[i])
a2.reverse
a1+=a2
print(*a1)