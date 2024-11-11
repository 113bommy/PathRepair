n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
s=0
s += sum(b)
for i in range(n-1):
    if a[i]==a[i+1]+1:
        s += c[i-1]
print(s)