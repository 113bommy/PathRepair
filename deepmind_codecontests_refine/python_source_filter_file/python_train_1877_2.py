import itertools
class dice():
    def __init__(self,number):
        self.number = number

    def korokoro(self,com):
        if com == 'E':
            self.number = [self.number[i] for i in [3,1,0,5,4,2]]
        if com == 'S':
            self.number = [self.number[i] for i in [4,0,2,3,5,1]]
        if com == 'N':
            self.number = [self.number[i] for i in [1,5,2,3,0,4]]
        if com == 'W':
            self.number = [self.number[i] for i in [2,1,5,0,4,3]]
def checker(d1,d2):
    for com in 'EEEENEEEENEEEENEEEENWSEEEENNEEEE':
        d1.korokoro(com)
        if d1.number == d2.number:
            ans = 'Yes'
            break
        else:
            ans = 'No'
    return ans
n = int(input())
saikoro = {}
for _ in range(n):
    saikoro[_] = dice([int(x) for x in input().split()])
l = list(itertools.combinations(saikoro.keys(),2))
for __ in l:
    test1 = saikoro[__[0]]
    test2 = saikoro[__[1]]
    if checker(test1,test2) == 'Yes':
        answer = 'Yes'
        break
    else:
        anser = 'No'
print(answer)

