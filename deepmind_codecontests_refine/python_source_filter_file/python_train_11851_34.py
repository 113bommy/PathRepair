N = int(input())

P2 = list(range(2,30001,2))
P3 = list(range(3,30001,6))
for i in range(1,5002):
  if (N-i*3)%2==0 and 0<(N-3*i)<=5000:
    x = 3*i
    y = (N-i*3)
    break
if N==5 or N>6:
  ans = P2[:x]+P3[:y]
elif N==3:
  ans = [2,5,63]
elif N==4:
  ans = [2,5,20,63]
elif N==6:
  ans = [2,3,4,185,7,9]
elif N==19999:
  ans = P2[:14997]+P3[:5000]+[19,425]
print(*ans)