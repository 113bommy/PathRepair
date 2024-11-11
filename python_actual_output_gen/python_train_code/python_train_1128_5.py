for i in range(int(input())):
    N = int(input())
    Answer = [0, 0, 0]
    for j in list(map(int, input().split())):
        Answer[j % 3] += 1
    Min = min(Answer[1], Answer[2])
    print(Answer[0] + (Answer[1] - Min) // 2 + (Answer[2] - Min) // 3 + Min)

# UB_CodeForces
# Advice: Don't afraid from failing, afraid from not trying
# Location: Behind my desk at home
# Caption: Nice weather
# CodeNumber: 466
