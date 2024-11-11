n=int(input())
l=[int(i) for i in input().split()]
s=sum(l)
mini=10**9 
p=0
for i in range(n-1):
    p+=l[i]
    mini=min(mini,abs(p-(s-p)))
print(mini)