number=int(input())
total=input()
total=total.split()
total=[int(i) for i in total]
total.sort()
summation=0
for i in range(number):
    summation=summation+total[i]*(i+2)
summation=summation-total[-1]
print(summation)