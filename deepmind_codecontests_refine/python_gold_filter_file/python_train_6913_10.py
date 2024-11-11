k,d=map(int,input().split())
if k!=1 and d==0:
    print("No solution")
else:
    number="0"*(k)
    number=number.replace('0',str(d),1)
    print((number))