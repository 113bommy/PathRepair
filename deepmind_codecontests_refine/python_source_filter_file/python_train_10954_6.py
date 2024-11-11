n=int(input())
b=list(map(int,input().split()))
p=[0]*(4*(10**5)+1)
for i in range(n):
    a=b[i]-i
    p[a]+=b[i]
print(max(p))