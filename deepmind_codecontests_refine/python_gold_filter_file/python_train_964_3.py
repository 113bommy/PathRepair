

def cal(s, n):
    #print(s, n)
    pits = []
    wins = []
    pit = 0
    win = 0
    for c in s:
        if c == 'W':
            win+=1
            if pit > 0:
                pits.append(pit)
                pit = 0
        else:
            pit += 1
            if win > 0:
                wins.append(win)
                win = 0
    if win > 0:
        wins.append(win)
    
    if s[0]=='L' and len(pits)>0:
        pit += pits[0]
        pits = pits[1:]
    
    
    pits = sorted(pits)
    fliped = 0
    adt = 0
    for p in pits:
        if fliped + p <= n:
            fliped += p
            adt += 1
        else:
            pit += p
    if n>= fliped+pit:
        return len(s)*2-1        
    if len(wins) == 0:
        return max(min(n,len(s))*2-1,0)
    
    #print('pits',pits,pit,wins,pit,adt,fliped,n-fliped)
    
    return sum(wins)*2-len(wins)+fliped*2+adt + min(n-fliped, pit)*2
#9*2-3=15   15+3*2+1+2*2=
    

def web():
    T = int(input())
    for t in range(1, T + 1):
        arr = [int(s) for s in input().split(" ")] 
        c = arr[1]
        s = input()
        ans = cal(s, c)
        print(ans)
              
def file():
    x = open('p2_in.txt')
    T = int(x.readline())
    for t in range(1, T + 1):
        arr = [int(s) for s in x.readline().split(" ")] 
        c = arr[1]
        s = x.readline()[:-1]
        ans = cal(s, c)
        print(ans)
#file()     
web()

'''
cd Desktop\Desktpop\coding contest\CodeJamQualify
python it_run.py python p4_runner.py 1 -- python p4.py
'''



