n,k=map(int,input().split())
t=input()
a=0
for i in range(1,n):
    if t[0:i]==t[n-i:n]:
        a=i
s=t+t[a:]*(k-1)
print(s)