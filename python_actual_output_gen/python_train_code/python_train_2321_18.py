s = input()
s = [s[i:i+1] for i in range(0, len(s), +1)]
if(len(s) <= 100):
    n = (s.count('n')-1)//2
    i = s.count('i')
    t = s.count('t')
    e = s.count('e')//3
    print(min(n,i,t,e))