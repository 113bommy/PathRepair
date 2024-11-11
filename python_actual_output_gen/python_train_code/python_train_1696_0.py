import sys
input = sys.stdin.buffer.readline

n,s=map(int,input().split())
if s>=2*n:
  print("YES")
  print("2"*(n-1)+str(s-n+1))
  print(1)
  
else:
  print("NO")