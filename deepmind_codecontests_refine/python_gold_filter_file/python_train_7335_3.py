n = int(input())
s1 = []
s2 = []
sum1, sum2 = 0, 0
for _ in range(n):
    num = input()
    n1 = int(num)
    if(n1 < 0):
        sum2 += -n1
        s2.append(-n1)
    else:
        sum1 += n1
        s1.append(n1)

if sum1 > sum2:
    print("first")
elif sum2 > sum1:
    print("second")
else:
    if s1 == s2:
        if n1 > 0:
            print("first")
        else:
            print("second")
    else:
        for i in range(n):
            if s1[i] != s2[i]:
                if s1[i] > s2[i]:
                    print("first")
                else:
                    print("second")
                break
