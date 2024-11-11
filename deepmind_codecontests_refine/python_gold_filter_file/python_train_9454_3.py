n=int(input())

m=-1

for i in range(3,1000,2):
    if i*i==8*n+1:
        m=(1+i)//2

if m==-1:
    print('No')
    exit(0)

cnt=1
s=[[0] for _ in range(m+1)]

for i in range(1,m+1):
    for j in range(i+1,m+1):
        s[i][0]+=1
        s[j][0]+=1

        s[i].append(cnt)
        s[j].append(cnt)

        cnt+=1

print('Yes')
print(m)
for i in range(1,m+1):
    print(' '.join([str(c) for c in s[i]]))