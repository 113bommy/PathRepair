import copy
 
n,k,c = map(int,input().split())
s = list(input())
 
front = []
back = []
 
# 前から貪欲
j = copy.copy(k)
i = 0
while j > 0:
  if s[i] == "o":
    front.append(i)
    i += c+1
    j -= 1
  else:
    i += 1
 
# 後ろから貪欲
 
j = copy.copy(k)
i = n-1
while j > 0:
  if s[i] == "o":
    back.append(i)
    i -= c+1
    j -= 1
  else:
    i -= 1

back.sort()
for i in range(k):
  if front[i] == back[i]:
    print(i+1)