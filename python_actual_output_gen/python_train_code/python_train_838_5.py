a = int(input())
if a%100<=((a-100*(a%100))*5):
    print(1)
else:
	print(0)