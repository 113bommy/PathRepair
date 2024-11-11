'''
Amirhossein Alimirzaei
Telegram : @HajLorenzo
Instagram : amirhossein_alimirzaei
University of Bojnourd
'''

N=[int(input()) for _ in range(3)]
for _ in range(N[0],0,-1):
    if (_*4)<N[2] and (_*2)<N[1]:
        print(_+_*2+_*4)
        exit()
print(0)