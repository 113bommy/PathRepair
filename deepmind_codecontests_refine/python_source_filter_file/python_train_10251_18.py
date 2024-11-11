import sys
n=0
for line in sys.stdin: 
    n = int(line)

result = 0 
if n%2 == 0:
    result = n/2
else: 
    result = - (n+1)/2

print(result)