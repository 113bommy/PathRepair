n=int(input())
*p,=map(int,input().split())
c=0
for i in range(n-1):
    c+=sorted(p[i:i+3])[1]==p[i+1]
print(c)