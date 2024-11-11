n=int(input())
a=list(map(int,input().split()))
s=max(a)
p=0
for i in a:
    p+=s-i
print(p)