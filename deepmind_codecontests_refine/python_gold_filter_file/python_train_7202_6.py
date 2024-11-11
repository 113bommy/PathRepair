

def main():

	genNb = []

	def gen_numbers(cur_nb):
		if cur_nb >= 9*1000000001:
			return
		genNb.append(cur_nb)
		gen_numbers(cur_nb*10+4)
		gen_numbers(cur_nb*10+7)

	gen_numbers(4)
	gen_numbers(7)

	left,right = map(int,input().split())

	sl = 0

	genNb.sort()

	for nb in genNb:
		if nb >= left:
			sl += nb*(min(nb,right)-left+1)
			left = nb+1
			if left > right:break
	print(sl)
main()