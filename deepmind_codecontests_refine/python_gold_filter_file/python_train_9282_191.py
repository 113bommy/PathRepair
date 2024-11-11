n=0
m=0
k=0

def Input():
  global n,m,k
  n,m,k=list(map(int,input().split()))

def Output():
  global n,m,k
  if m>=n and k>=n:
    print('Yes')
  else:
    print('No')

if __name__ == '__main__':
  Input()
  Output()