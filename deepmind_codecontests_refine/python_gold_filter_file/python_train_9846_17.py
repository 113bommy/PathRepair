#758A Holiday Of Equality

n = int(input())
entrada = str(input())
entrada = entrada.split()

welfare = [int(x) for x in entrada]

equality_number = max(welfare) 

suma = 0

for x in welfare:
    suma += equality_number - x

print(suma)