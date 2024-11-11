N=int(input())
ans=''
whileN>0:
  N-=15
  ans+=chr(ord('a')+N%26)
  N//=26
print(ans[::-1])