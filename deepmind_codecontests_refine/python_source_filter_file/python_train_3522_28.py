def main():
  import math
  n=int(input())
  CSF=[list(map(int,input().split())) for _ in [0]*(n-1)]
  t=0
  for i in range(n-1):
    t=CSF[i][1]
    for csf in CSF[i:]:
      c,s,f=csf[0],csf[1],csf[2]
      t=math.ceil(max(s,t)//f)*f+c      
    print(t)
  print(0)
if __name__=='__main__':
  main()