N = int(input())
a = list(map(int,input().split()))
R = [0]*9
for r in a:
  rr = r//400
  if rr < 8:
    R[rr] = 1
  else:
    R[8] += 1
s2 = sum(R)
s1 = s2 - R[8]
print(s1,s2)