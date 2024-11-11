n = int(input())
st =  input()
genome = "ACTG"
# print(ord("Z"))
asd = n-4+1
# print(ord("V"))
m = []
for i in range(asd):
  sum=0
  
  sum += min(abs(ord(st[i]) - ord(genome[0])),abs(abs(ord(st[i]) - ord(genome[0]))-26))
#   print (abs(ord(st[i]) - ord(genome[0])))
#   print(abs(abs(ord(st[i]) - ord(genome[0]))-26))
#   print(sum)
  sum += min(abs(ord(st[i+1]) - ord(genome[1])),abs(abs(ord(st[i+1]) - ord(genome[1]))-26))
#   print(sum)
  sum += min(abs(ord(st[i+2]) - ord(genome[2])),abs(abs(ord(st[i+2]) - ord(genome[2]))-26))
#   print(sum)
  sum += min(abs(ord(st[i+3]) - ord(genome[3])),abs(abs(ord(st[i+3]) - ord(genome[3]))-26))
#   print(sum)
#   print(sum)
  m.append(sum)
print(min(m))
  