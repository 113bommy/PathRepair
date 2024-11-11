n = int(input())

final_n = n
counter = 0

if not(n % 2):
	final_n = n / 2

elif not(n % 3):
	final_n = n / 3

elif not(n % 5):
	final_n = n / 5

elif not(n % 7):
	final_n = n / 7

else:
	final_n = n - 1

for x in range(1, int(final_n + 1)):
	if not(n % x):
		counter += 1

print(counter)
