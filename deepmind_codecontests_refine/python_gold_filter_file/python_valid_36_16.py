for _ in range(int(input())):
 n=int(input())
 if n <= 5:
  print('abcde'[:n])
 else:
  print('a'*(n//2-1)+'bc'[:1+(n%2)]+'a'*(n//2))