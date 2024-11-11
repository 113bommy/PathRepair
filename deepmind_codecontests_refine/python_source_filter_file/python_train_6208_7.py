a=list(map(int,input().split()))
s=sum(a)/2

b=False
for i in range(0,4):
    for j in range(i+1,5):
        for k in range(j+1,6):
            if i+j+k==s:
                b=True
print('YES' if b else 'NO')
