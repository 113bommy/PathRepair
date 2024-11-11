#A. The King's Race
n=int(input())
x, y=map(int, input(). split())
def king(n, x, y):
  for i in range (n):
    if y >= x and y-1 <= n-x  or y<=x and x-1<= n-y:
      return ('white')
    else :
      return ('black')
print (king(n, x, y))