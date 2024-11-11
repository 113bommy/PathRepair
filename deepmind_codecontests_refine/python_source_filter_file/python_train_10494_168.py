N,A,B,C,D = map(int,input().split())
S=input()
ans="Yes"

if D<C:
  triple = S[B-1:D+2].count("...")
  if triple ==0:
    ans="No"

double= S[A-1:max(C,D)].count("##")
if double > 0:
  ans="No"
  
print(ans)