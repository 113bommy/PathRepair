import math

(A, B) = map(int, input().split())
count = 0

next_pow = int(math.pow(2, math.ceil(math.log(B,2))))
y = next_pow - 2 #has only 1 zero
while y >= A:
	delta = ~y & (y+1)
	if delta << 2 & y == 0:
		delta += 1

	if A <= y and y <= B:
		count+=1

	y -= delta

print(count)