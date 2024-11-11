# A. Heist
n=int(input())
s=list(map(int,input().split()))
s.sort()
c=0
for i in range(n-1):
    if s[i+1]-s[i]>1:
        c+=abs(s[i+1]-s[i])-1
print(c)