for _ in " "*int(input()):
    a=int(input());z="NO"
    k=list(map(int,input().split()))
    for i in range(a-2):
        if k[i] in k[i+2:]:z="YES";break
    print(z)