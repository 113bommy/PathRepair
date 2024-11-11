N=int(input())
prev=2
now=1
for i in range(N-2):
  prev,now=now,now+prev
print(now)