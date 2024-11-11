import math

class Fighter:
    def __init__(self,attack_power,number_techniques):
        self.attack_power = attack_power
        self.number_techniques = number_techniques
    
    def fight(self,other,monster):
        turnDamage = self.attack_power + other.attack_power
        actualHP = int(monster.hp % turnDamage)
        if(actualHP == 0):
            actualHP = turnDamage
        usedTechniques = int(math.ceil(actualHP / self.attack_power))
        return usedTechniques
            
class Monster:
    def __init__(self,hp):
        self.hp = hp

n,a,b,k = input().split()

you = Fighter(int(a),int(k))
opponent = Fighter(int(b),0)

h = list(map(int, input().split()))
monsterList = list()

for i in h:
    x = Monster(i)
    monsterList.append(x)
h.clear()

techList = list()

for i in monsterList:
    techList.append(you.fight(opponent,i))

techList.sort()
techniquesUsed = 0
monstersDefeated = 0

for i in techList:
    if(techniquesUsed + i <= you.number_techniques):
        monstersDefeated += 1
        techniquesUsed += i
    else:
        break

print(monstersDefeated)