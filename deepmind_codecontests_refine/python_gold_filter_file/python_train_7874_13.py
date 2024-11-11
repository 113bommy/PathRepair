for i in range(10):
    print(i)
    inp= input()
    kaj=['great','don\'t think so','cool','not bad','don\'t touch me']
    if inp == 'no':
        continue
    if inp in kaj:
        print('normal')
        break
    if inp not in kaj:
        print('grumpy')
        break