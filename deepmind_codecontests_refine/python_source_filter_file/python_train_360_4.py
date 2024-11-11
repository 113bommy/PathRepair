def merge(parte1, parte2):
    if parte1 < parte2:
        return f'{parte1}{parte2}'
    return f'{parte2}{parte1}'

def divide(paravra):
    tamanho = len(paravra)
    if tamanho == 1:
        return paravra
    centro = tamanho // 2

    parte1 = divide(paravra[:centro])
    parte2 = divide(paravra[centro:])
    return merge(parte1, parte2)


palavra1 = input()
palavra2 = input()

palavra1 = divide(palavra1)
palavra2 = divide(palavra2)

if palavra1 == palavra2:
    print("YES")
else:
    print("NO")