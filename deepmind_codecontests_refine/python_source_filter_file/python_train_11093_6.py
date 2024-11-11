from sys import stdin
from sys import exit
from math import sqrt

#parser
def parser():
    return map(int, stdin.readline().split())

def IsPrime(t):
    if t<2:
        return False
    if t==4:
        return True
    for i in range(2,int(sqrt(t))+1):
        if t%i==0:
            return False
    return True

def rp_found_begin_pos(side_length,number_of_sides,begin_pos):
    pos=begin_pos
    while number_of_sides!=0:
        if not knights_mood[pos]:
            return False
        pos+=side_length
        number_of_sides-=1
    return True

#Comprobar existencia de un poligono regular
def rp_found(side_length,number_of_sides):
    for i in range(side_length):
        if rp_found_begin_pos(side_length,number_of_sides,i):
            return True
    return False

n=int(stdin.readline())
knights_mood=[x for x in parser()]

divisors=[]
n_sqrt=int(sqrt(n))

for i in range(1,n_sqrt+1):
    if n % i == 0:
        i_couple=int(n/i)
        if IsPrime(i):
            divisors.append((i,i_couple))
        if IsPrime(i_couple):
            divisors.append((i_couple,i))

for pair in divisors:
    first_divisor=pair[0]
    second_divisor=pair[1]
    if rp_found(second_divisor,first_divisor):
        print('YES')
        exit()

print('NO')