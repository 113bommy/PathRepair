pontoAx, pontoAy = [int(i) for i in input().split()]
pontoBx, pontoBy = [int(i) for i in input().split()]
pontoCx, pontoCy = [int(i) for i in input().split()]

x4, x5 = pontoBx - pontoAx, pontoCx - pontoBx
y4, y5 = pontoBy - pontoAy, pontoCy - pontoBy
direcao = x4 * y4 - x5 * y5

if direcao > 0:
    print('LEFT')
elif direcao < 0:
    print('RIGHT')
else:
    print('TOWARDS')
