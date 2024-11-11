n = input()
idx = int(n) % 4 
suma = 1 + 2**idx + 3**idx + 4**idx 

suma = suma % 5
print(suma)