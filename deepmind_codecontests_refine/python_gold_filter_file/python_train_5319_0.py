input()
m=int(input())
v=m
try:
 for a in map(int, input().split() + input().split()):
   v*=a
   v/=a-1
 print(v-m)
except ZeroDivisionError:
 print(-1)