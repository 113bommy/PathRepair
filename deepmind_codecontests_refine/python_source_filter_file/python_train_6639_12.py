def m()
  N=input()
  A=sorted(map(int,input().split()))
  M=A[-1]+1
  B=[0]*M
  for i in A:
    B[i]+=1
    if B[i]==1:
      for j in range(i*2,M,i):
        B[j]=2
  print(B.count(1))
m()