X,K,D= map(int, input().split()) 
X=abs(X)
R=X//D
if R>=K:
  print(abs(X-K*D))
elif (K-R)%2==0:
  print(abs(X-K*R))
else:
  print(abs(X-K*(R+1)))
  