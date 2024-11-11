# your code goes here
A = []
B = []
C = []
AB = []
BC = []
AC = []
ABC = []
n = int(input())

for __ in range(n):
	j, c = input().split()
	j = int(j)
	c = ''.join(sorted(list(c))) 
	if c == 'A':
		A.append(j)
	elif c == 'B':
		B.append(j)
	elif c == 'C':
		C.append(j)
	elif c == 'AB':
		AB.append(j)
	elif c == 'BC':
		BC.append(j)
	elif c == 'AC':
		B.append(j)
	elif c == 'ABC':
		ABC.append(j)

		

l = []
if A and B and C:
	l.append(min(A) + min(B)+ min(C))
if AB and BC and AC:
	l.append(min(AB) + min(BC)+min(AC))
if AB and C:
	l.append(min(AB)+min(C))
if A and BC:
	l.append(min(A)+min(BC))
if AC and BC:
	l.append(min(AC)+min(BC))
if AB and BC:
	l.append(min(AB)+min(BC))
if AC and AB:
	l.append(min(AC)+min(AB))
if AC and B:
	l.append(min(AC)+min(B))
if ABC:
	l.append(min(ABC))
	
print(min(l) if l else -1)
