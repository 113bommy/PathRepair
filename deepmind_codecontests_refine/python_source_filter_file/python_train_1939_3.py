n = int (input())
w = list(map(int, input().split()))
w.sort()
print(w)
swd=[0,0]
for i in range(n*2-1):
    swd.append(swd[i]+(w[i+1]-w[i]))
m = swd[n*2]
for i in range(n):
    for j in range(0,n-i):
        s = swd[i*2] +  swd[(i+j)*2+1]-swd[i*2+1] + swd[n*2]-swd[(i+j+1)*2]
        if s<m:
            m=s
print (m)
