class Fighter:
    def __init__(self, attack_power, number_techniques):
        self.attack_power = attack_power
        self.number_techniques = number_techniques
    def fight(self, other, monster):
        sum_attack_power = self.attack_power + other.attack_power
        mod = monster.hp % sum_attack_power
        if(mod == 0):
            #entonces antes de que yo de mi último golpe (sin tomar en cuenta mi habilidad), el monstruo tiene sum_attack_power puntos de vida.
            vida_restante = sum_attack_power 
        else:
            #de lo contrario, la vida que le queda al monstruo es justamente el módulo
            vida_restante = mod

        #ataco por última vez sin usar mi habilidad
        vida_restante = vida_restante - self.attack_power
        if(vida_restante <= 0): #si lo maté, entonces no necesité ayuda de mi técnica especial por lo que retorno 0
            return 0
        else:
            #si no lo maté, entonces debo usar mi habilidad especial
            return (vida_restante + self.attack_power - 1) // self.attack_power
                 
            
class Monster:
    def __init__(self, hp):
        self.hp = hp

#code
(n,a,b,k) = tuple(map(int, input().split(' '))) #tomo el primer input de una forma cómoda.
health_points = list(map(int, input().split(' '))) #tomo la lista de puntos de vida para los n monstruos.

points = 0 #inicializo los puntos en 0 para luego comenzar a aumentarlos
me = Fighter(a,k)
my_opponent = Fighter(b,0)
my_list = list()
for i in range(n):
    my_list.append(me.fight(my_opponent, Monster(health_points[i])))
    #print("For the monster " + str(i) + ": " + str(me.fight(my_opponent, Monster(health_points[i]))))
my_list.sort()
for number_tech_needed in my_list:

    if(number_tech_needed == 0):
        points = points + 1
    else:
        if(k >= number_tech_needed):
            points = points + 1
            k = k - number_tech_needed
print(points)