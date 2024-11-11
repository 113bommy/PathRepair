import heapq

def play(words):        
    s01 = set()
    s10 = set()
    s11 = 0
    s00 = 0

    for w in words:
        if w[0] == '0':
            if w[-1] == '0':
                s00 += 1
            else:
                s01.add(w)
        elif w[-1] == '0':
            s10.add(w)
        else:
            s11 += 1


    if (s11 > 0 or s00 > 0) and len(s01) == 0 and len(s10) == 0:
        print(-1)
        return


    diff = max(len(s01), len(s10)) - min(len(s01), len(s10))
    
    # если разница в количестве s01 и s10 меньше или равна 1, то никаких перестановок делать не надо. Пример: 100, 001, 10
    if diff <= 1:
        print(0)
        print('')
        return

    # если разница > 1, то достаточно взять diff / 2 из одного множества, перевернуть слова и переместить в другое множество
    # при этом, гарантированно не будет повторений слов после переворота, т.к у нас может быть максимум min(len(s01), len(s10)) 
    # повторений после переворота слов, а значит среди max(len(s01), len(s10)) можно выбрать diff уникальных

    change = int(diff / 2)
    indices = []
    if len(s01) > len(s10):
        i = 0
        for w in words:            
            i += 1
            if w[0] == '0' and w[-1] == '1':
                wr = w[::-1]
                if not wr in s10:
                    indices.append(i)            
            if len(indices) >= change:
                break
    else:
        i = 0
        for w in words:            
            i += 1
            if w[0] == '1' and w[-1] == '0':
                wr = w[::-1]
                if not wr in s01:
                    indices.append(i)            
            if len(indices) >= change:
                break        
    
    print(change)
    print(*indices)


def main():
    t =  list(map(int, input().split()))[0]

    while t > 0:        
        n = int(input())
        arr = []
        while n > 0:
            arr.append(input())
            n -= 1
        play(arr)
        t -=1    
    
main()
# play(['0001', '1000', '0011', '0111'])
# play(['010', '101', '0'])
# play(['00000', '00001'])
# play(['01', '001', '0001', '00001'])
