fu=input()
numbers=list(map(int,input().split()))
num1 = numbers.count(1)
num2 = numbers.count(2)
num3 = numbers.count(3)
Min = min(num1,num2,num3)
ind1 = ind2 = ind3 = -1
print(Min)
l = ''
for i in numbers:
    try:
        c1 = numbers.index(1,ind1+1)
        ind1 = c1
        c2 = numbers.index(2,ind2+1)
        ind2 = c2
        c3 = numbers.index(3,ind3+1)
        ind3 = c3
    except:
        pass
    print(c1+1,c2+1,c3+1)
