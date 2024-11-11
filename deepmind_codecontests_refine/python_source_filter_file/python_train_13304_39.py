L,R=map(int,input().split())
r=min(R,L+2019*2)
minimum=2019*2
for i in range(L,r+1):
    for j in range(i+1,r+1):
        minimum=min(minimum,i*j%2019)
print(minimum)