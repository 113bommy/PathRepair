def comb(n, r):
  return n == ( r | (n - r) ) 
  
N=int(input())
S=input()
x=0;
b=1;
for i in range(N):
  s=int(S[i])%2;
  x=(x+s*(comb(N-1,i)))%2;
  b*=s%2;
if(x%2 or b==0):
  print(x%2);exit();
x=0;
for i in range(N):
  s=(int(S[i])/2)%2;
  x=(x+s*(comb(N-1,i)))%2;

print((x%2)*2);