mi = map(int, input().split())
minutes = list(mi)
wr = map(int, input().split())
wrong = list(wr)
hs, hu = map(int, input().split())
max_point = [500, 1000, 1500, 2000, 2500]
score = 0

def Score_law(x, m, w) :
    fir = 0.3 * x
    sec = abs( ( (1 - (m / 250) ) * x ) - (50 * w) )
    law = max(fir, sec)
    return law

def getHacks(hs, hu) :
    suc_hack = hs * 100
    unsuc_hack = hu * 50
    hack_score = suc_hack - unsuc_hack
    return hack_score

for i in range(5) :
    x = max_point[i]
    m = minutes[i]
    w = wrong[i]
    score += Score_law(x, m, w)

hack_score = getHacks(hs, hu)
total_Score = int(score + hack_score)

print(total_Score)
