n,one,two = map(int,input().split())
T = list(map(int,input().split()))
half = 0
count = 0
for i in T:
  if i == 1:
    if one>0:
      one -=1
    elif two>0:
      two -=1
      half += 1
    elif half>0:
      half -=1
    else:
      count += 1
  else:
    if two>0:
      two -=1
    else:
      count += 1
print(count)
    