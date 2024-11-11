a,b=map(int,input().split())
lt=[0]+[int(i) for i in input().split()]+[b]
lton,ltoff=[0],[0]*(2-a%2)
for i in range(1,a+2,2):
    lton+=[lton[(i+1)//2-1]+lt[i]-lt[i-1]]
for i in range(a+2,1,-2):
    ltoff+=[ltoff[(a+2-i)//2+1-a%2]+lt[i-1]-lt[i-2]]
m=lton[-1]
for i in range(1,a+2):
    if lt[i]-1==lt[i-1]:
        pass
    elif i%2:
        m=max(m,lt[i]-lt[i-1]-1+lton[(i-1)//2]+ltoff[(a+2-i)//2])
    else:
        m=max(m,lt[i]-lt[i-1]-1+lton[i//2]+ltoff[(a+2-i)//2])
print(m)
