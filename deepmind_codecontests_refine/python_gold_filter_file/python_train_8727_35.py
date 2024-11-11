N = int(input())
for ai in range(N//4,3500):
    for bi in range(N//4,3500):
        try:
            ci = N*ai*bi/(4*ai*bi-N*ai-N*bi)
        except:
            continue
        if ci == int(ci) and ci > 0:
            print(ai,bi,int(ci))
            exit()
