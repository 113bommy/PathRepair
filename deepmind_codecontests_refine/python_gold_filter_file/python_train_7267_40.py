def main():
  
  n=int(input())
  num=[int(i) for i in input().split()]
  c1,c2,c3=0,0,0
  
  for i in range(n):
    if num[i]==1:
      c1+=1
    elif num[i]==2:
      c2+=1
    else:
      c3+=1
  a=c1+c2+c3+1
  b=c2+c3+1
  c=c3+1
  
  dp=[[[0]*a for _ in range(b)] for _ in  range(c)]
  
  for i in range(c):
    for j in range(b-i):
      for k in range(a-i-j):
        tmp=i+j+k
        if tmp==0:
          continue
        else:
          dp[i][j][k]=n/tmp
          if i>0:
            dp[i][j][k]+=i*dp[i-1][j+1][k]/tmp
          if j>0:
            dp[i][j][k]+=j*dp[i][j-1][k+1]/tmp
          if k>0:
            dp[i][j][k]+=k*dp[i][j][k-1]/tmp
  print(dp[c3][c2][c1])
             
if __name__=='__main__':
  main()