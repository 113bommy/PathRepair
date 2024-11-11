from collections import deque

def calculate1(x, y) :
    if   x == 0 : y.appendleft(y.popleft() + y.popleft())
    elif x == 1 : y.appendleft(y.popleft() - y.popleft())
    else : y.appendleft(y.popleft() * y.popleft())
    return y

def calculate2(x, y) :
    if   x == 0 : y.append(y.pop() + y.pop())
    elif x == 1 : y.append(y.pop() - y.pop())
    else : y.append(y.pop() * y.pop())
    return y

def search1(sample) :
    for first in range(3) :
        for second in range(3) :
            for third in range(3) :
                box = deque(sample)
                calculate1(first, box)
                calculate1(second, box)
                calculate1(third, box)
                if box[0] == 10 :
                    return(first,second,third)
                    break
                
def search2(sample) :
    for first in range(3) :
        for second in range(3) :
            for third in range(3) :
                box = deque(sample)
                calculate1(first, box)
                calculate2(second, box)
                calculate1(third, box)
                if box[0] == 10 :
                    return(first,second,third)
                    break

def attack(sample) :
    test = [[sample[a],sample[b],sample[c],sample[d]] for a in range(4) for b in range(4) for c in range(4) for d in range(4) if a!=b and a!=c and a!=d and b!=c and b!=d and c!=d]
    test = list(set(map(tuple, test)))
    for _ in test : 
        result = search1(_)
        if result != None :
            return result, _, 1
            break
        else :
            result = search2(_)
            if result != None :
                return result, _, 2
                break

ams = ['+', '-', '*']
while True :
    sample = [int(_) for _ in input().split()]
    if sample == [0, 0, 0, 0] : break
    result  = attack(sample)
    if result != None :
        if result[2] == 1 : print('(({} {} {}) {} {}) {} {}'.format(result[1][0], ams[result[0][0]], result[1][1], ams[result[0][1]], result[1][2], ams[result[0][2]], result[1][3]))
        else : print('({} {} {}) {} ({} {} {})'.format(result[1][0], ams[result[0][0]], result[1][1], ams[result[0][2]], result[1][2], ams[result[0][1]], result[1][3]))
    else : print(0)