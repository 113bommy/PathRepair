input()
m=int(input())
try:
 for a in map(int, input().split() + input().split()):
   m*=a
   m/=a-1
 print(m)
except ZeroDivisionError:
 print(-1)