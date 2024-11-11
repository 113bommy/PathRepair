a, z = map(int, input().split())
s = input()
c = input().split();r=0;p=0;k=0
while r<a:
    if s[r] not in c:
        n=len(s[p:r])
        k=k+(n*(n+1))//2
        p=r+1
    r+=1
n=len(s[p:])
k=k+(n*(n+1))//2
print(k)