# encoding:utf-8

def main():
	n, k = list(map(int, input().split()))
	nums = list(map(int, input().split()))
	
	seat_two = n * 2
	seat_four = n
	seat_one = 0
	n_four = sum([x // 4 for x in nums])
	nums = [x % 4 for x in nums]
	n_two = sum([x // 2 for x in nums])
	n_one = sum([x % 2 for x in nums]) 

	print(n_one, n_two, n_four)
	print(seat_one, seat_two, seat_four)

	if seat_four >= n_four:
		# there is rest of 4 seat
		seat_four -= n_four
		n_four = 0

		# break seat seat_one and seat_two
		seat_two += seat_four
		seat_one += seat_four
		seat_four = 0
	else:
		# there is rest of 4 people
		n_four -= seat_four
		seat_four = 0

		# break 4 people to 2, 2
		n_two += n_four * 2
		n_four = 0

	print(n_one, n_two, n_four)
	print(seat_one, seat_two, seat_four)


	if seat_two >= n_two:
		seat_two -= n_two
		n_two = 0
		if seat_two + seat_one >= n_one:
			print("YES")
		else:
			print("NO")
	else:
		n_two -= seat_two
		seat_two = 0
		n_one += n_two * 2
		if seat_one >= n_one:
			print("YES")
		else:
			print("NO")

if __name__ == '__main__':
	main()
