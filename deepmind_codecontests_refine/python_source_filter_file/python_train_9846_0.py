x=int(input())
n=list(map(int,input().split()))
w=max(n)
p=1
for i in  n:
    p+=w-i
print(p)