from collections import defaultdict


def factorial(n, m, rep):
    r = 1
    for i in range(2, n + 1):
        j = i
        while j % 2 == 0 and rep > 0:
            j /= 2
            rep -= 1
        r *= j
        r %= m
    return r



n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
m=int(input())
ans=1
d=defaultdict(lambda:0)
e=defaultdict(lambda:0)

i=0
while(i<n):
    d[a[i]]+=1
    d[b[i]]+=1
    if a[i]==b[i]:
        e[a[i]]+=1
    i+=1
ans=1
for j in d:
    k=d[j]
    rep=e[j]
    ans=(ans*factorial(k,m,rep))
    ans=ans%m
print(ans)






