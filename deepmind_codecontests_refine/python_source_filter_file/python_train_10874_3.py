from sys import stdin, stdout


def main():
    p = 1000000007  # Constante brindada por el problema
    n, h = readline()
    a = list(readline())
    for i in range(n):  # Se calculan las diferencias entre h y los numeros de la secuencia
        a[i] = h - a[i]
        if a[i] < 0:  # El valor del numero es superior al de h deseado
            return 0
    if a[0] > 1 or a[n - 1] > 1:  # Es imposible que uno de los extremos alcance el valor de h
        return 0
    for i in range(1, n):  # Se calculan las diferencias entre los valores de las posiciones consecutivas
        a[i] -= a[i - 1]
        if a[i] > 1 or a[i] < -1:  # La diferencia es superior a la necesaria para que haya solucion
            return 0
    answer = 1
    count = 0
    for i in range(n):
        if a[i] == 1:  # Existe un segmento que se inicia en esta posicion
            count = count + 1 % p
        elif a[i] == -1:  # Existe un segmento que termina en la posicion anterior
            answer = answer * count % p
            count -= 1
        else:  # No ocurre ninguno de los dos casos anteriores, o ambos a la vez
            answer = answer * (count + 1) % p
    return answer


def readline():  # Metodo para leer una linea completa, dividirla en elementos y convertirlos en numeros enteros
    return map(int, stdin.readline().strip().split())


if __name__ == '__main__':
    stdout.write(str(main()) + '\n')
