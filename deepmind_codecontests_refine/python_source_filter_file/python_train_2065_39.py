N=int(input())
L=list(map(int,input().split()))
cnt=0
while all(l%2==0 l in L):
  L=[l/2 for l in L]
  cnt+=1
print(cnt)