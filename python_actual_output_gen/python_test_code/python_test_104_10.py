n = int(input())

scores = []
rating = "maybe"
standings = -1
for i in range(n):
    score = list(map(int, input().split(' ')))
    scores.append(score)

counter = False
for score in scores:
    if score[0] < score[1]:
        rating = "rated"
        break
    else:
        if not counter:
            counter = True
        else:
            if score[0] > standings:
                rating = "unrated"
        standings = score[0]
print(rating)
