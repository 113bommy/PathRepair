n = int(input())

for i in range(n):
    s = input()
    if s[-2::1] == 'po':
        print('FILIPINO')
    if s[-4::1] == 'desu' or s[-2::1] == 'masu':
        print('JAPANESE')
    if(s[-5::1]) == 'mnida':
        print('KOREAN')
