n, m = map(int,input().split())

an = m //n
while an*n != m:
  an = m//n
  n = 1 + (m-1)*an
  
print(an)
