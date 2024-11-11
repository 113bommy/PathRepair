t = int(input())

for i in range(t):
    n = int(input())
    r, p, s = map(int, input().split())
    sequence = input()
    R = sequence.count('R')
    P = sequence.count('P')
    S = sequence.count('S')
    sequence = sequence.replace("R","a")
    sequence = sequence.replace("P","b")
    sequence = sequence.replace("S","c")
    if R > p:
        win_p = p
    else:
        win_p = R
    if P > s:
        win_s = s
    else:
        win_s = P
    if S > r:
        win_r = r
    else:
        win_r = S
    wins = win_p + win_s + win_r
    if wins >= n//2:
        print("YES")
        winsequence = sequence.replace("a","P", p)
        winsequence = winsequence.replace("b","S", s)
        winsequence = winsequence.replace("c","R", r)
        num_r = r - winsequence.count("R")
        num_p = p - winsequence.count("P")
        num_s = s - winsequence.count("S")
        winsequence = winsequence.replace("a","R", num_r)
        winsequence = winsequence.replace("a","P", num_p)
        winsequence = winsequence.replace("a","S", num_s)
        num_r = r - winsequence.count("R")
        num_p = p - winsequence.count("P")
        num_s = s - winsequence.count("S")
        winsequence = winsequence.replace("b","R", num_r)
        winsequence = winsequence.replace("b","P", num_p)
        winsequence = winsequence.replace("b","S", num_s)
        num_r = r - winsequence.count("R")
        num_p = p - winsequence.count("P")
        num_s = s - winsequence.count("S")
        winsequence = winsequence.replace("c","R", num_r)
        winsequence = winsequence.replace("c","P", num_p)
        winsequence = winsequence.replace("c","S", num_s)
        print(winsequence)
    else:
        print("NO")
    