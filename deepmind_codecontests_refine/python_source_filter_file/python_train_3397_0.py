n,m,d=map(int, input().split())
key={}
for i in range(26):
    key[chr(ord('a')+i)]=-1
    key[chr(ord('A')+i)]=-1
a=[]
for i in range(n):
    a.append(input())
shift=[]
for i in range(n):
    for j in range(m):
        if a[i][j]=="S":
            shift.append((i,j))
for i in range(n):
    for j in range(m):
        ch=a[i][j]
        if ch>="a" and ch<="z":
            key[ch]=0
            ch=ch.upper()
            if key[ch]<0 and len(shift)>0:key[ch]=1
            for (x,y) in shift:
                if (i-x)**2+(j-y)**2<=d:
                    key[ch]=0
                    break
res=0
input()
for ch in input():
    if key[ch]<0:
        print(-1)
        exit()
    else:
        res+=key[ch]
print(res)
    
    
                    
