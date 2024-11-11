n, q = map(int, input().split())
sups = list(map(int, input().split()))

dir_subs = [[] for i in range(n+1)]
num_subs = [0]*(n+1)

sups = [0,0]+sups
for i in range(2, n+1):
	dir_subs[sups[i]].append(i)

#ordered = [1]
prev_parent = 0
#qe = [-1]+dir_subs[1]
qe = [1]
ordered = []

while len(qe)>0:
	new = qe.pop()

	if new > 0:
		#new_parent = sups[new]
		ordered.append(new)
		#num_subs[new_parent] += 1
		
		#qe = dir_subs[new] + [-new] + qe
		qe.append(-new)
		num = len(dir_subs[new])
		for i in range(num):
			qe.append(dir_subs[new][num-1-i])

		#if new_parent == prev_parent:
		#	num_subs[new_parent] += num_subs[curr_parent]
		#	prev_parent = new_parent
	else:
		parent = -new
		for child in dir_subs[parent]:
			num_subs[parent] += 1
			num_subs[parent] += num_subs[child]

print(num_subs)
print(ordered)
# [0, 8, 0, 5, 0, 2, 0, 1, 0, 0]


indices = [0]*(n+1)

for i in range(n):
	indices[ordered[i]] = i

def ans_query(u, k):
	if k-1 > num_subs[u]:
		return -1
	
	start = indices[u]
	end = ordered[start+k-1]
	return end

s = ''
for i in range(q):
	u, k = map(int, input().split())
	s += (str(ans_query(u,k))+'\n')
	if i%20 == 0:
		print(s[:-1])
		s = ''

if len(s) > 0:
	print(s[:-1])