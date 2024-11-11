from queue import PriorityQueue
import copy
import math

nmlist = input()
nm = [int(i) for i in nmlist.split()]

qnt_pessoas = nm[0]
qnt_comida = nm[1]

coef = int(qnt_comida/qnt_pessoas)

comida = {}

mlist = input()
for i in mlist.split():
    i = int(i)
    if i not in comida:
        comida[i] = 0
    comida[i] += 1

q = PriorityQueue()

for i in comida:
    q.put((-comida[i], i))


def last_n_days(days, q):
    qcopy = PriorityQueue()
    qcopy.queue = copy.deepcopy(q.queue)

    last = 0
    
    n = qnt_pessoas
    while not qcopy.empty() and n > 0:
        entry = qcopy.get()
        last += (-entry[0])//days

        #print(days, entry, last)
        n -= 1
    '''
    for i in range(qnt_pessoas):
        entry = qcopy.get()
        eat = entry[0] + days
        if eat == 0:
            last += 1
        elif eat < 0:
            last += 1
            qcopy.put((eat, entry[1]))
        else:
            break
    '''
    return last - qnt_pessoas


def busca_binaria(left, right):
    repeat = 0
    while True:
        mid = int((left + right)/2)

        res = last_n_days(mid, q)

        #print(left, right, mid, res)

        if abs(left - right) == 1:
            repeat += 1
        
        if left - right == 0 or repeat > 10:
            return mid
        
        if res >= 0:
            left = mid
        else:
            right = mid
        

if qnt_pessoas > qnt_comida: 
    print(0)
elif last_n_days(coef, q) == 0:
    print(coef)
else:
    print(busca_binaria(1, coef))
