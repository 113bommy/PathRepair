n = int(input())
for _ in range(n):
    s = input()
    if s[:-2] == 'po':
        print('FILIPINO')
    elif s[-4:] in ['desu', 'masu']:
        print('JAPANESE')
    elif s[-4:] == 'mnida':
        print('KOREAN')
