t = int(input())
def sh(n):
    if n == 2 or n == 3:
        return 2
    if n%2==0:
        return n//2 +1
    return (n+1)//2+1
for i in range(t):
    n = int(input())
  
    print(sh(n))