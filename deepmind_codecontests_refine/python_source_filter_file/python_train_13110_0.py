def secMax(a):
    mx = 0
    smx = 0
    for i in range(0,len(a)):
        if a[i] > mx:
            smx = mx
            mx = a[i]
        elif a[i] > smx:
            smx = a[i]
    else:
        return smx

while True:
    n = int(input())
    if n == 0:
        break
    c = list(map(str,input().split()))
    ##alphabet = char('a')##char型ねぇよって言われた(´・ω・`)
    alph = ["A","B","C","D","E","F","G","H",
            "I","J","K","L","M","N","O","P","Q",
            "R","S","T","U","V","W","X","Y","Z"]
    abcCount = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    for i in range(0, n):
        for j in range(0, 26):
            if c[i] == alph[j]:
                abcCount[j] = abcCount[j] + 1
                break
        print(abcCount)
        if max(abcCount) > n-1-i+secMax(abcCount):
            print(alph[abcCount.index(max(abcCount))], sum(abcCount))
            break
    else:
        print("TIE")

