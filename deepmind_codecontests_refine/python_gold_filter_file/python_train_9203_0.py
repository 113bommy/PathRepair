import sys

def readInputs():
    global budget, prices
    budget = int(f.readline())
    prices = []
    for _ in range(4):
        (a1,b1,a2,b2) = map(int,f.readline().split())
        prices += [((a1,b1),(a2,b2))]
    #print(budget)
    #print(prices)
    

def isPartOk(a,b):
    for i in range(4):
        ((a1,b1),(a2,b2)) = prices[i]
        #print(a,((a1,b1),(a2,b2)))
        if((a >= a1 or a >= b1) and (b >= a2 or b >= b2)):
            return i+1
    return -1

def solve():
    for a in range(1,budget):
        res = isPartOk(a,budget-a)
        if(res!=-1):
            return ' '.join([str(res),str(a),str(budget-a)])
    return -1

def main():
    global f
    f = sys.stdin
    readInputs()
    print(solve())
    
main()