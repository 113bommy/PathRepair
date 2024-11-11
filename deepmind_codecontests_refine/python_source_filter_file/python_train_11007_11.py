n = int(input())
c = 0
while n>0:
  if n//100>0:
    c += n//100
    n = n%100
  elif n//20>0:
    c += n//20
    n = n%20
  elif n//10>0:
    c += n//10
    n = n%10
  elif n//5>0:
    c += n//5
    n = n%5
  elif n//1>0:
    c += 1
    n = n-1
  print(n)
print(c)