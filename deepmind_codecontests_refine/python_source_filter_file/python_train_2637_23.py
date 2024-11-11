from math import ceil
input()
s = input().split()
n = s.count('4')
#print(n)

s3 = s.count('3')
n += s3
#print(n)

s2 = s.count('2')
if s2%2:
	n += (s2+1)/2
	s2r = 1
else:
	n += s2/2
	s2r = 0
#print(n)

s1 = s.count('1')
s1r = s1 - s3 if s1 > s3 else 0

if s2r:
	s1r -= 2 if s1r >= 2 else 0

n += ceil(s1r/4)
#print(n)
print(int(n))