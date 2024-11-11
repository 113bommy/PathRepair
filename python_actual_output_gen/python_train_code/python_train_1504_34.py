N = int(input())

ans = ''

while N>0:
  N-=1
  ans += chr(ord('a')+N%26)
  N //= 2
 
print(ans[::-1])