import copy
import sys

def cuenta(tablero, letra):
    minimo = 10
    for i in range(0, 8):
        for j in range(0, 8):
            if(tablero[i][j] == letra):
                k = i-1
                while(k >= 0):
                    if(tablero[k][j] != '.'):
                        break
                    k -= 1
                if(k < 0):
                    minimo = min(minimo, i)
    return minimo

tablero = []
for i in range(1, 9):
    line = input()
    tablero.append(line)
    
A = cuenta(tablero, 'W')
for i in range(0, 4):
    aux = copy.copy(tablero[i])
    tablero[i] = copy.copy(tablero[8-i-1])
    tablero[8-i-1] = aux

#for i in range(0, 8):
#    print(tablero[i])
B = cuenta(tablero, 'B')
if(A <= B):
    print("A")
else:
    print("B")
#print(A, B)