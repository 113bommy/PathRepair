n,ans = int(input()),0
s = list(input())
for i in range(n+1):ans = max(ans,s.count("I")-s.count("D"))
print(ans)