n = int(input())
Sum = 0
classA = list(map(int,input().split()))
classB =list(map(int,input().split()))
w=False
for i in range(1,6) :
    if (classA.count(i)+classB.count(i)) %2 == 1:
        w=True
        break

    else:
        Sum += abs(classA.count(i) - classB.count(i))

if w:
    print (-1)

else:
    print(int(Sum/4))