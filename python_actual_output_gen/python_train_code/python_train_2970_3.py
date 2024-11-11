N = int(input())
s = list(input())

def judge() :
    # 要するに最初の2個を決めれば良い
    for comb in (('S', 'S'), ('S', 'W'), ('W', 'S'), ('W', 'W')) :
        t = [None] * N
        t[0], t[1] = comb
            
        for i in range(1, N - 1) :
            if (s[i] == 'o') == (t[i] == 'S') :
                t[i + 1] = t[i - 1]
            else :
                t[i + 1] = 'S' if t[i - 1] == 'W' else 'W' 
        
        con1 = ((s[0] == 'o') == (t[0] == 'S')) == (t[N-1] == t[1])
        con2 = ((s[N - 1] == 'o') == (t[N - 1] == 'S')) == (t[N-2] == t[0])
        if con1 and con2 :
            return ''.join(t)
        
        return -1
print(judge())