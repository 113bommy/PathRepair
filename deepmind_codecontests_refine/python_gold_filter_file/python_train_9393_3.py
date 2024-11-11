def test(n):
    if n == 1 or n == 0:
        return(-1)
    resposta = ''
    for j in range(n - 1):
        resposta += '3'

    resposta+='4'
    return(resposta)

x = int(input())
for i in range(x):
    n = int(input())
    print(test(n))



    
