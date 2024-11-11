def cal( s , c ):
  w = [0 , 0]
  for i in range(len(s)):
    if s[i] != c:
      w[ i % 2 ] += 1
    c = 'r' if c == 'b' else 'r'
  return min(w[0], w[1])
n = int( input() )
s = input()
print( min( cal( s , 'r' ) , cal( s , 'b' ) ) )
