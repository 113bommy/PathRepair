def answer(testCase) :
    participants, firstCard, secondCard = testCase
    _sum = firstCard + secondCard
    _min = participants
    _max = participants

    if firstCard == participants and secondCard == participants :
        return str(participants) + " " + str(participants)
    
    # min찾기
    if firstCard+secondCard <= participants :
        _min = 1
    else :
        _min = (firstCard + secondCard + 1) - participants
    
    if firstCard+secondCard >= participants :
        _max = participants
    else :
        _max = firstCard + secondCard - 1

    return str(_min) + " " + str(_max)

testCaseCount = int(input())
testCases = []
for _ in range(0, testCaseCount):
    testCases.append(list(map(int, input().split())))

for i in range(0, testCaseCount) :
    print(answer(testCases[i]))