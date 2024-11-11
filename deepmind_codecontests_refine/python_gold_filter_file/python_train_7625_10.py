for i in"*"*int(input()):
    s=input()
    l=[s.count("S"),s.count("P"),s.count("R")]
    print(["S","P","R"][l.index(max(l))-1]*len(s))