while True:
    _=input()
    if _ == '-':
        break
    for i in range(int(input())):
        l=int(input())
        _=_[l:]+_[:l]
    print(_)    
