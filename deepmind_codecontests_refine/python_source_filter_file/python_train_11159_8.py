def main():
    testcase = int(input())
    result = []
    positive_total = 0
    negative_total = 0
    positivOdd = []
    negativeOdd = []
    for i in range(testcase):
        cin = int(input())
        div = cin / 2
        result.append(div)
        if cin % 2 == 0:
            if(cin >= 0):
                positive_total += div
            else:
                negative_total += div
        else:
            if cin >= 0:
                positive_total += div
                positivOdd.append(i)
            else:
                negative_total += div
                negativeOdd.append(div)
    negative_total *= -1
    while negative_total != positive_total:
        if(positive_total < negative_total):
            result[positivOdd.pop()] += 1
            positive_total += 1
        else:
            result[negativeOdd.pop()] -= 1
            negative_total += 1
    for i in result:
        print(i)

main()
