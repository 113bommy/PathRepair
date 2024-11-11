'''Problem 18A - Triangle'''
import  math
a1,a2,b1,b2,c1,c2 = map(int, input().split())

def is_triangle(ip,c1,c2):
    if c1 == 0 or c2 == 0 : return False

    return math.trunc(ip*100000)/100000 == math.trunc(math.sqrt(pow(c1,2) + pow(c2,2))*100000)/100000

def pitagora_th(n=[0]*6):
    ab = math.sqrt((a1 + n[0] - (b1 + n[2]))**2 + (a2 + n[1] - (b2 + n[3]))**2)
    bc = math.sqrt((b1 + n[2] - (c1 + n[4]))**2 + (b2 + n[3] - (c2 + n[5]))**2)
    ca = math.sqrt((c1 + n[4] - (a1 + n[0]))**2 + (c2 + n[5] - (a2 + n[1]))**2)
    e = [ab,bc,ca]
    e.sort()
    return e[0], e[1], e[2]

a3, b3, c3 = pitagora_th()
if is_triangle(c3, a3, b3):
    print('RIGHT')
    exit()
else:
    for i in range(6):
        moves ,movess = [0]*6, [0]*6
        moves[i] = 1
        movess[i] =-1
        a, b, c = pitagora_th(moves)
        if is_triangle(c,b,a) :
            print('ALMOST')
            exit()
        a, b, c = pitagora_th(moves)
        if is_triangle(c,b,a):
            print('ALMOST')
            exit()


print('NEITHER')
