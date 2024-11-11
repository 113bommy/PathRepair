n=int(input())
k=''
i=1
while len(k)<=(n+1):
    u=str(i)
    k+=u
    i=i+1
print(k[n-1])