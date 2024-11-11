for s in[*open(0)][2::2]:
    a=[int(i) for i in s.split()]
    a.sort()
    print(((sum(a)-a[-1])/len(a)-1)+a[-1])