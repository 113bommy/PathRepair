backet = [0]*(ord('z') - ord('a') + 1)
h,w = map(int,input().split())
for _ in range(h):
  a = list(input())
  for i in a:
    backet[ord(i) - ord('a')] += 1

mod = [0,0,0,0]
for i in backet:
  mod[i%4] += 1
ans = False
if h%2 and w%2:
  if mod[1] + mod[3] == 1 and (mod[2]+mod[3] - (h//2+w//2))%2 == 0 and mod[2]+mod[3] - (h//2+w//2) >= 0:
    ans = True
elif h%2:
  if mod[1]+mod[3] == 0 and (mod[2]+mod[3]-w//2)%2==0 and mod[2]+mod[3]-w//2>=0:
    ans = True
elif w%2:
  if mod[1]+mod[3] == 0 and (mod[2]+mod[3]-h//2)%2 == 0 and mod[2]+mod[3]-h//2 >= 0:
    ans = True
else:
  if mod[1] == mod[2] == mod[3] == 0:
    ans = True
if ans:
  print('Yes')
else:
  print('No')
