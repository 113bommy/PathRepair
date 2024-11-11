from bisect import bisect
X=int(input())
K=int(input())
rs=[0]
for r in input().split():
  rs.append(int(r))
A=[[(0,0),(X,X)]]
min_sup=0
max_inf=X
pre_r=0
for i,r in enumerate(rs[1:]):
  d=r-pre_r
  pre_r=r
  m,M=A[-1][0][0],A[-1][1][0]
  if i%2==0:
    if m-d>=0:
      new_m=m-d
    else:
      new_m=0
      min_sup=min_sup+d-m
    if M-d>0:
      new_M=M-d
    else:
      new_M=0
      max_inf=0
  else:
    if M+d<=X:
      new_M=M+d
    else:
      new_M=X
      max_inf=max_inf-(d-(X-M))
    if m+d<X:
      new_m=m+d
    else:
      new_m=X
      min_sup=X
  if new_m==new_M:
    min_sup=X
    max_inf=0             
  A.append([(new_m,min_sup),(new_M,max_inf)])
Q=int(input())
for q in range(Q):
  t,a=map(int,input().split())
  r_num=bisect(rs,t)-1
  m,min_sup=A[r_num][0]
  M,max_inf=A[r_num][1]
  r=rs[r_num]
  if r_num%2==0:
    if a<=min_sup:
      print(max(m-(t-r),0))
    elif min_sup<a<max_inf:
      print(max(m+(a-min_sup)-(t-r),0))
    else:
      print(max(M-(t-r),0))
  else:
    if a<=min_sup:
      print(min(m+(t-r),X))
    elif min_sup<a<max_inf:
      print(min(m+(a-min_sup)+(t-r),X))
    else:
      print(min(M+(t-r),X))
