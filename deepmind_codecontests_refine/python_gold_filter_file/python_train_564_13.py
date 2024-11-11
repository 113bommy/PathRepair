import sys
# sys.stdin = open('input.txt','r')
s = input()
t = input()
s_count = [0]*26
t_count = [0]*26
for i in range(len(s)):
	s_count[ord(s[i])-ord('a')]+=1
for i in range(len(t)):
	t_count[ord(t[i])-ord('a')]+=1

tree = False
array = False
automation = False

for i in range(26):
	if s_count[i] < t_count[i]:
		tree = True
	if s_count[i] > t_count[i]:
		automation=True

i = 0

for j in range(len(t)):
	while i < len(s) and s[i] != t[j]:
		i+=1
	if i == len(s):
		array = True
	i+=1
if tree:
	print('need tree')
elif automation and array:
	print('both')
elif automation:
	print('automaton')
elif array:
	print('array')

