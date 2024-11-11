import sys
l=[list(map(float,i.split(","))) for i in sys.stdin]
bmi=lambda i:i[1]/(i[2]**2)
[print(int(i[0])) for i in l bmi(i)>=25]
