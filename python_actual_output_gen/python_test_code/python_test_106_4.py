n,k=map(int,input().split())
l=[]
for i in range(1,min(k+1,10)):
    if n%i in l:
        print('No')
        exit()
    l.append(n%i)
print('Yes')