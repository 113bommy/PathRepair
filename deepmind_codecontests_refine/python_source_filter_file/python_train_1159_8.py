n = int(input())
a = list(map(int,input().split()))
a.sort()
for i in range(0,n,2):
    print(a[i],end=" ")
s=[]
for i in range(1,n,2):
    s.append(str(a[i]))
a.reverse()
print(" ".join(s))
