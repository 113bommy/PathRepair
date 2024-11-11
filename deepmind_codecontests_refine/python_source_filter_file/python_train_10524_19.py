n = int(input())
e,g,m,h=map(int,input().split())
thomas_mark=e+g+m+h
thomas_rank =1
for i in range(1,n):
  e,g,m,h=map(int,input().split())
  others_mark=e+g+m+h
  if (others_mark>thomas_mark):
    thomas_rank +=1
thomas_rank