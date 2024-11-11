count1 = 0
count2 = 0
N, A, B = map(int, input().split())
S = list(input())
for i in S:
  if i == "a" and A + B >= count1:
    print("Yes")
    count1 += 1
  elif i == "b" and A + B >= count1 and B >= count2:
    print("Yes")
    count1 += 1
    count2 += 1
  else :
    print("No")