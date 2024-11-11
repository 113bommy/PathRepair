n, c = map(int, input().split())
p = [int(x) for x in input().split()]
t = [int(x) for x in input().split()]

def pointsForLimak(n, c, p, t):
    pointsSoFar = 0
    minutesBefore = 0
    for i in range(0, n):
        minutesTaken = t[i]
        subtractions = c * (minutesTaken + minutesBefore)
        pointsAvailableForCurrentProblem = p[i]
        pointswon = pointsAvailableForCurrentProblem - subtractions
        if pointswon < 0:
            pointswon = 0

        pointsSoFar = pointsSoFar + pointswon
        minutesBefore = minutesBefore + minutesTaken

        #print("On problem " + str(i + 1) + ", Limak gets " + str(pointswon) + " points")
        #print("At the end of problem " + str(i + 1) + ", the time taken for Limak is " + str(minutesBefore))

    return pointsSoFar

def pointsForRadewoosh(n, c, p, t):
    pointsSoFar = 0
    minutesBefore = 0
    for i in range(n - 1, - 1, - 1):
        minutesTaken = t[i]
        subtractions = c * (minutesTaken + minutesBefore)
        pointsAvailableForCurrentProblem = p[i]
        pointswon = pointsAvailableForCurrentProblem - subtractions
        if pointswon < 0:
            pointswon = 0

        pointsSoFar = pointsSoFar + pointswon
        minutesBefore = minutesBefore + minutesTaken

        #print("On problem " + str(i + 1) + ", Radewoosh gets " + str(pointswon) + " points")

    return pointsSoFar

limak = pointsForLimak(n, c, p, t)
radewoosh = pointsForRadewoosh(n, c, p, t)

#print(limak)
#print(radewoosh)

if limak > radewoosh:
    print("Limac")

elif limak < radewoosh:
    print("Radewoosh")

elif limak == radewoosh:
    print("Tie")