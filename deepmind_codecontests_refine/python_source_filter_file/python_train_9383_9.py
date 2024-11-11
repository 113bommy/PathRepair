a = [int(i) for i in input().split()]
n = a[0]
k = a[1]
m = a[2] 
a = [int(i) for i in input().split()]
sum_a = sum(a)

def boost(q, energy):
	max_boost = energy	
	if max_boost > k*q :
		max_boost = k*q
	return max_boost


max_boost = boost(n, m)
average = (sum_a + max_boost)/n
people = n
energy = m
a.sort()
for i in range(n):
	if people - 1 != 0 and energy - 1 != 0:
		max_boost = boost(people - 1, energy - 1)
		tmp_average = (sum_a - a[i] + max_boost)/(people - 1)
		if average < tmp_average:
			energy -= 1
			people -= 1
			sum_a -= a[i]
			average = tmp_average
print(average)