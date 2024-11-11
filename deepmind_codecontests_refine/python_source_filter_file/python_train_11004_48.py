n = int(input())

def getBillsCount(amount, bills):
	count = 0
	for bill in sorted(bills, reverse=True):
		if amount == 0: break

		numOfBills = amount//bill
		if (numOfBills > 0):
			amount -= bill * numOfBills
			count += numOfBills
		
	return count

billsValues = [1,5,10,20, 50,100]
print(getBillsCount(n, billsValues))