from typing import SupportsFloat


n = input()

i = len(n) - 1
while (i >= 0):
    
    if (int(n[i]) >= 5):
        print("-O | ", end = "")
    else:
        print("O- | ", end = "")  
    
    j = 0
    while (j < int(n[i]) % 5):
        print("O", end = "")
        j+=1


    print ("-", end = "")
    
    j = 0
    while (j <  4 - int(n[i]) % 5):
        print("O", end = "")
        j+=1
    
    if (i != 0):
        print ("\n")

    i-=1


