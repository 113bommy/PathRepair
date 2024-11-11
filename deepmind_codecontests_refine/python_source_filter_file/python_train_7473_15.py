N = int(input()); MOD = pow(10,9)+7
C= list(map(int,input().split()))
C.sort()

#L = [48,20,8,3,1]
L = [1]
for i in range(1,N):
  temp = (i+2)*pow(2,i-1)
  L.append(temp)
  
L.reverse()
ans = 0
for i in range(N):
  ans = (ans + L[i]*pow(2,i)*C[i])%MOD
#ans = ans%MOD
print(ans*pow(2,N,MOD)%MOD)
