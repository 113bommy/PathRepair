def main():
  l,r=0,10**9
  while r-l>1:
    m=(l+r)//2
    if sum([(i-1)//m for i in a])<=k: r=m;
    else: l=m;
  print(r)

if __name__=='__main__':
  n,k=map(int,input().split())
  a=list(map(int,input().split()))
  main()