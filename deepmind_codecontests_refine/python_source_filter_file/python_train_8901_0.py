l = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
a, b = map(int, input().split())
s = str(list(range(a, b+1)))
print(s)
print(6*s.count('0')+2*s.count('1')+5*s.count('2')+
      5*s.count('3')+4*s.count('4')+5*s.count('5')+6*s.count('6')+
      3*s.count('7')+7*s.count('8')+6*s.count('9'))

