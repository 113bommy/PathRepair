def Input():
    Str= input('')
    List = Str.split(' ')
    for i in range(len(List)):
        List[i] = int(List[i])
    return List

def Twice(List,n):
    Count = 0
    for i in range(len(List)):
        if List[i] == n:
            Count += 1
        if Count == 2:
            break
    return Count

def Mex(List):
    N = 0
    Done = False
    while Done == False:
        x = Twice(List,N)
        if x == 0 or x == 1:
            Done = True
        else:
            N += 1
    M = N
    if x != 0:
        Done = False
        N += 1
    while Done == False:
        x = Twice(List,N)
        if x == 0:
            Done = True
        else:
            N += 1
    return [M,N]
            
            

trials = int(input(''))
for i in range(trials):
    input('')
    List = Input()
    print(Mex(List))

