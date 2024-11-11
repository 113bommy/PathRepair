def solution(s):
    t = "AHIMOoTUVvWwXxY"
    pol = {"A" : "A",
           "b" : "d",
           "d" : "b",
           "H" : "H",
           "I" : "I",
           "M" : "M",
           "O" : "O",
           "o" : "o",
           "p" : "q",
           "q" : "p",
           "T" : "T",
           "U" : "U",
           "V" : "V",
           "v" : "v",
           "W" : "W",
           "w" : "w",
           "X" : "X",
           "x" : "x",
           "Y" : "Y"}

    for i in range(len(s)//2):
        if s[i] in pol:
            if s[len(s) - i - 1] != pol[s[i]]: return "NIE"
        else: return "NIE"
    
    #print(s[len(s)//2])
    if len(s)%2:
        if s[len(s)//2] in t: return "TAK"
        else: return "NIE"
    else: 
        if pol[s[len(s)//2 - 1]] == s[len(s)//2]: return "TAK"
        else: return "NIE"

print(solution(input()))