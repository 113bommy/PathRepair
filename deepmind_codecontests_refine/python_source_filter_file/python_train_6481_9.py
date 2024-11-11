for g in [*open(0)][2::2]:
    i=0
    d=(g+'1*').split()
    while'1'==d[i]:
        i+=1
    print('FSiercston d'[i%2::2])