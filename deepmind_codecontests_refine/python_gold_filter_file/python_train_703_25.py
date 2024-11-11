n,m=map(int,input().split())
sc=[list(map(int,input().split())) for i in range(m)]
start=10**(n-1)
end=10**n
if n == 1:
    start = 0
for i in range(start,end):
    i=str(i)
    for s,c in sc:
        if i[s-1] != str(c):
            break
    else:
        print(i)
        exit()
print(-1)