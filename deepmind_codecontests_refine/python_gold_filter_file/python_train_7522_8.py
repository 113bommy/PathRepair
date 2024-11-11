for item in [0]*int(input()):
    input()
    a = list(map(int,input().split()))
    count =0
    for item in a:
        if item>=0:
            count =count+item
        if item<0:
            if count+item>=0:
                count =count+item
            else:
                count =0
    print(count)