k = int(input())
a,b = map(int,input().split())
if -(-b//k)*k -k>=a:
  print("OK")
else:
  print("NO")
