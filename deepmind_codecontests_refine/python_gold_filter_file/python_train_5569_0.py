#Les datas
n, k = [int(s) for s in input().split()]

#On initie fibo
fibo = [0] * max(2, n);
fibo[0] = 1;
fibo[1] = 1;
for i in range(2, n):
    fibo[i] = fibo[i-1] + fibo[i-2];

def f(k):
    return fibo[k-1];

#Une pseudo fonction de dichotomie sur fibo (retourne l'indice de valeur inférieure)
def dico(n, v):
    i, j = 2, n;
    if f(j) <= v:
        return j, f(j);
    if v == 1:
        return 2, 1;
    while j-i > 1:
        m = j-i // 2;
        if f(m) < v:
            i = m
        elif f(m) == v:
            return m, v;
        else:
            j = m;
    return i, f(i);

#On détermine les positions des doublets
currentLine = 1;
pos = []
long = n; #La longueur retante après les doublets déjà mis


while currentLine != k:
    i, v = dico(long, k-currentLine);
    currentLine += v;
    pos.append(n-i+1);
    long = i-2;

#On construit la réponse
prec = 0;
for p in pos:
    for i in range(prec+1, p):
        print(i, end = " ");
    print(p+1, p, end = " ");
    prec = p+1;
for i in range(prec+1, n+1):
    print(i, end = " ");
