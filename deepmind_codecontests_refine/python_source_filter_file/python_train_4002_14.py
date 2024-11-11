def main():
	a1 = "poiuytrewqlkjhgfdsamnbvcxz"
	a2 = "POIUYTREWQLKJHGFDSAMNBVCXZ"
	a3 = "0987654321"

	s = input()
	ind0 = ind1 = ind2 = ind3 = False

	ind0 = (len(s) >= 5)

	for c in s:
		ind1 |= (c in a1)
		ind2 |= (c in a2)
		ind3 |= (c in a3)

	if ind0 & ind1 & ind2 & ind3:
		print("Correct")
	else:
		print("Too week")

main()