N,M=map(int,input().split())
SC=[list(map(int,input().split())) for i in range(M)]
begin=10**(N-1)
end=10**N
if N==1:
  begin=0
for i in range(begin,end):
  i=str(i)
  for s,c in SC:
    if i[s-1]!=str(c):
      break
  else:
    print(i)
    exit()
print(-1)