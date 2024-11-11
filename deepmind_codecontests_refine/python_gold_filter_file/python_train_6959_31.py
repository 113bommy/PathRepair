n=int(input())
import math
for i in range (int(math.sqrt(n)),0,-1):
  if n%i==0:
    print(max(len(str(i)),len(str(n//i))))
    quit()
