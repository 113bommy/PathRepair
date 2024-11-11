amount = input()
iamount = int(amount)

if iamount >= 0:
    print (iamount)

else:
    iamount = -1 * iamount
    print (-1 * min(iamount// 10, (iamount // 100 ) * 10 + iamount % 10))
