n=int(input())
l=list(map(int,input().split()))
p=0
for i in range(n):
    p+=l[i]
print(p/n)