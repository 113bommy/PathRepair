N=int(input())
for m in range(1,5*10**3):
    if m*(m+1)//2>=N:
        break

for i in range(m,0,-1):
    if N>=i:
        print(i)
        N-=i
    elif N==0:
        break
