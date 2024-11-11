n = list(map(int, input("").split(" ")))

if n[0]%2==0:
    temp1 = n[0]//2
else:
    temp1 = n[0]//2+1

if temp1>n[1]:
    ans = 2*n[1]-1
else:
    ans = 2*(n[1]-temp1)

print(ans)
