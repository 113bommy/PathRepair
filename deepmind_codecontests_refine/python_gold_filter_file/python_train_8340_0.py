import sys

n = int(sys.stdin.readline())

seq = (sys.stdin.readline()).strip()
seq = seq.split()
seq = [int(elem) for elem in seq]

n_half = n//2
out = [0]*n

upper, lower = seq[-1]//2, seq[-1]- seq[-1]//2
out[n//2], out[n//2-1] = lower, upper
offset = 1
for i in range(n_half-2,-1,-1):
	cur = seq[i]
	upper_cur = cur//2
	lower_cur = cur - cur//2
	if lower_cur<lower:
		lower_cur,upper_cur = lower,upper_cur-(lower-lower_cur)
	if upper_cur>upper:
		upper_cur,lower_cur = upper, lower_cur+(upper_cur-upper)
	lower,upper = lower_cur, upper_cur
	out[n//2+offset] = lower
	out[n//2-1-offset] = upper
	offset+=1

out = [str(elem) for elem in out]
print(' '.join(out))
	

		
