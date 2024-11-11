import random
from math import gcd, sqrt, floor, ceil


#__________________________________________________#
# brute force solution_____________________________#
def solve_1(n):
    d = divisors(n)
    order = [0] * len(d)
    moves = [999999999] * 1
    mark = [False] * len(d)
    permutation(d, [0] * len(d), 0, moves, mark, order)

    if gcd(order[0], order[-1]) == 1:
        moves[0] += 1

    return order, moves[0]

def permutation(d, p, pos, moves, mark, order):
    if pos == len(d):
        m = 0
        for i in range(len(p) - 1):
            if gcd(p[i], p[i + 1]) == 1:
                m += 1
        if m < moves[0]:
            moves[0] = m
            for i in range(len(p)):
                order[i] = p[i]
        #print(p)
        return

    for i in range(len(d)):
        if not mark[i]:
            mark[i] = True
            p[pos] = d[i]
            permutation(d, p, pos + 1, moves, mark, order)
            mark[i] = False

    return

def divisors(n):
    d = []
    for i in range(2, int(sqrt(n)) + 1):
        if(n % i == 0):
            d.insert(floor(len(d)/2), i)
            if(i * i != n):
                d.insert(ceil(len(d)/2), n//i)
    d.append(n)
    return d


#__________________________________________________#
# solution_________________________________________#
def solve_2(n):
    d = divisors(n)
    moves = 0

    order = sort_1(d)
    if(gcd(order[0], order[len(order) - 1]) == 1):
        moves += 1

    return order, moves

def sort(divs):
    order = []
    order.append(divs[0])
    count = len(divs)
    divs.remove(divs[0])

    while(len(order) < count):
        for d in divs:
            if gcd(d , order[-1]) != 1:
                order.append(d)
                divs.remove(d)
                break
    return order

def sort_1(divs):
    order = []
    order.append(divs[0])
    count = len(divs)
    divs.remove(divs[0])

    while len(order) < count:
        if gcd(divs[0], order[-1]) == 1:
            lcm = (divs[0] * order[-1]) // gcd(divs[0], order[-1])
            order.append(lcm)
            divs.remove(lcm)

        order.append(divs[0])
        divs.remove(divs[0])
    return order



#__________________________________________________#
# main_____________________________________________#
def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        #order, moves = solve_1(n)   #solucion_fuerza_bruta
        order, moves = solve_2(n)   #solucion_eficiente
        print(' '.join(str(j) for j in order))
        print(moves)
    return


# _________________________________________________#
# random cases tester______________________________#
def random_cases():
    n = random.randint(2, 50)
    print('Case: \n' + "n = " + str(n))
    order, moves = solve_1(n)   #solucion_fuerza_bruta
    #order, moves = solve_2(n)   #solucion_eficiente
    print(' '.join(str(i) for i in order))  #solucion
    print(moves)

    return


#__________________________________________________#
# tester___________________________________________#
def tester():
    for i in range(1, 20):
        n = random. randint(4, 50)
        order_1, moves_1 = solve_1(n)
        order_2, moves_2 = solve_2(n)

        print('Case ' + str(i) + ':\n' + 'n = ' + str(n))
        print('solucion fuerza bruta : \n' + ' '.join(str(i) for i in order_1) + '\n' + str(moves_1))  #solucion_fuerza_bruta
        print('solucion eficiente : \n' + ' '.join(str(i) for i in order_2) + '\n' + str(moves_2))     #solucion_eficiente
        for i in range(min(len(order_1), len(order_2))):
            if(order_1[i] != order_2[i] or len(order_1) != len(order_2) or moves_1 != moves_2):
                print('Wrong Answer\n')
                return
        print('Accepted\n')
    return


main()            #entrada_de_casos_por_consola
#random_cases()    #casos_random
#tester()          #tester_automatico