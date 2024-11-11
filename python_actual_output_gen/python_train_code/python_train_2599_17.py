a=int(input())
b=[]
c=0
d=0
for i in range(a):
    c=list(map(int,input().split()))
    b.append(c)

for i in range(len(b)):
        d+=b[i][i]
        d+=b[0-i-1][0-i-1]
        d+=b[(a-1)//2+1][i]
        d+=b[i][(a-1)//2+1]
print(d-(b[(a-1)//2][(a-1)//2]*3))