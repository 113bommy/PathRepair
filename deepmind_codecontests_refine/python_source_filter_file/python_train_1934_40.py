import sys
input = sys.stdin.readline
 
n=int(input())

if n%2 == 0:
    ans1 = n//2
    ans2 = [2]*ans1
else:
    ans1=n//2-1
    ans2 = [2]*ans1
    ans2.append(3)
    
    
print(ans1)
print(*ans2)
