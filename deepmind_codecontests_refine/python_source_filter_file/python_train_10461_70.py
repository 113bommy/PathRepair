import sys
temp = sys.stdin.readline()


while temp:
    

    k, n, w = temp.split(" ")
    k = int(k)
    n = int(n)
    w = int(w)
      
    
    aux = ((w)*(w+1))* k/2
    if aux - n < 0:
        print(0)
    else:
        print(aux - n)
    temp = sys.stdin.readline()