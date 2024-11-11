'''
Amirhossein Alimirzaei
Telegram : @HajLorenzo
Instagram : amirhossein_alimirzaei
University of Bojnourd'''

n=list(map(int,input().split()))
print("YES" if ((abs(n[0]-n[2])*n[3])+(n[5]*3)+(abs(n[2]-n[1])*n[4]))<=(abs(n[0]-n[1])*n[3]) else "NO")