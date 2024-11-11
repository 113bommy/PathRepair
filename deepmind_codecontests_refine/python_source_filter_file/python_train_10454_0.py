import sys
import itertools

k, x, n, m = map(int, input().split())

def valid(inicio, fim, tamanho, num_ac):
    if num_ac == 0:
        if tamanho == 1:
            return ("" if inicio != fim else inicio)
        elif tamanho == 2:
            return (inicio + fim if inicio + fim != "AC" else "")
        else:
            return inicio + "B" * (tamanho - 2) + fim
    
    s = "AC" * num_ac
    if (not s) or s[0] != inicio:
        s = inicio + s

    if len(s) > tamanho or len(s) == tamanho and s[-1] != fim:
        return ""

    s += fim * (tamanho - len(s))
    return s


a = [0] * 51
a[1] = 1
b = [0] * 51
b[2] = 1
for i in range(3, 51):
    a[i] = a[i-2] + a[i-1]
    b[i] = b[i-2] + b[i-1]

for letters in itertools.product(['A', 'B', 'C'], repeat=4):
    first_s1 = letters[0]
    last_s1 = letters[1]
    first_s2 = letters[2]
    last_s2 = letters[3]
    
    c = [0] * 51
    
    meio = last_s1 + first_s2
    c[3] = (1 if meio == "AC" else 0)
    
    for i in range(4, 51):
        meio = last_s2 + (first_s2 if i % 2 == 0 else first_s1)
        c[i] = c[i-2] + c[i-1] + (1 if meio == "AC" else 0)
       
    for occ1 in range(0, 51):
        tmp = x - a[k] * occ1 - c[k]
        if tmp % b[k] != 0:
            continue
        tmp = tmp//b[k]
        if tmp < 0 or tmp > 50:
            continue

        s1 = valid(first_s1, last_s1, n, occ1)
        s2 = valid(first_s2, last_s2, m, tmp)

        if s1 and s2:
            print(s1)
            print(s2)            
            sys.exit(0)

print("Happy new year!")
