import math

n=int(input())
for i in range(int(math.sqrt(n)),n+1):
    if n%i==0:print(max(len(str(i)),len(str(n//i))));break