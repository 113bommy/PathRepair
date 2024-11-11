#!/usr/env/python3

n = int(input())
tt = list(map(int, input().split(" ")))

cc = 0
for i in range(len(tt)-1):
  mm = tt.pop(i)
  ss = sum(tt)
  if ss % 2 == 0: cc += 1
  tt.insert(i,mm)
print(cc+1)
