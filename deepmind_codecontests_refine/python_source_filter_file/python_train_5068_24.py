n,bit = map(int,input().split())
a = list(map(int,input().split()))

b = list()
ch = 0

for i in range(n-1):
    if(a[i]%2==0):
        ch += 1
    elif(a[i]%2==1):
        ch -= 1
    
    if(ch==0):
        b.append(abs(a[i]-a[i+1]))
    
b.sort()
cn = 0
for i in range(len(b)):
    if(bit>b[i]):
        bit-=b[i]
        cn+=1

print(cn)