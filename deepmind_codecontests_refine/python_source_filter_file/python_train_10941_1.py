n = int(input())
a = [1000000,1000000,1000000,1000000,1000000,1000000,1000000]

for i in range(n):
    s = input()
    k = s.split(" ")
    q = int(k[0])
    p = k[1]
    
    p = sorted(p)
    p = "".join(p)
    
    if(p=='A' or p=='B' or p=='C'):
        a[int(ord(p[0])-ord('A'))] = min(a[int(ord(p[0])-ord('A'))],q)
    elif(p=='AB'):
        a[3] = min(a[3],q)
    elif(p=='AC'):
        a[4] = min(a[4],q)
    elif(p=='BC'):
        a[5] = min(a[5],q)
    elif(p=='ABC'):
        a[6] = min(a[6],q)

# print(a)

x = a[0]+a[1]+a[2]
y1 = a[4]+a[5]
y2 = a[3]+a[4]
y3 = a[3]+a[5]
y4 = a[0]+a[5]
y5 = a[1]+a[4]
y6 = a[2]+a[3]
z  = a[6]
# print(x,y1,y2,y3,y4,y5,y6,z)

ans = min(x,y1,y2,y3,y4,y5,y6,z)
if(ans>100000):
    print(-1)
else:
    print(ans)