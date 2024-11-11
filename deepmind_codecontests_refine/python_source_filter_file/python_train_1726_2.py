def same(kefa,sasha,length):
    i = 0
    svkefa = int(length) - int(kefa[-1]) + int(kefa[0])
    svsasha = int(length) - int(sasha[-1]) + int(sasha[0])
    while i < len(kefa)-1:
        kefa[i] = int(kefa[i+1]) - int(kefa[i])
        sasha[i] = int(sasha[i+1]) - int(sasha[i])
        i += 1
    kefa[-1] = svkefa
    sasha[-1] = svsasha
    i = 0
    while i < len(kefa):
        e = 0
        array = sasha[i:] + sasha[:i]
        while True:
            if kefa[e] != array[e]:
                 break
            e += 1
            if e < len(kefa):
                return True
        i += 1
    return False
i = input().split(' ')
print('YES' if same(list(map(int,input().split(' '))),list(map(int,input().split(' '))),i[1]) else 'NO')