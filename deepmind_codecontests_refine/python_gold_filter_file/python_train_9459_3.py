n=int(input())
a=[(int(input()),i) for i in range(n)]
#print(a)
a.sort()
#print(a)
ans=0

for i in range(n):
    ans+=(a[i][1]-i)%2
print(ans//2)
