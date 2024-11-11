t = int(input())

'''
各テストケースの唯一の行は4つの整数a,b,c,d (1≤a,b,c,d≤109) - ポリカープがリフレッ
シュするために眠る時間，最初のアラームが鳴るまでの時間，それに続くアラームが鳴るまでの時間
，ポリカープが眠りにつくまでに費やした時間である．
'''
for i in range(t):
    a, b, c, d = map(int, input().split())
    nokori = a
    res = b
    
    nokori -= b
    
    if nokori <= 0:
        print(res)
    else:
        #n = 1
        if c <= d:
            print(-1)
        else:
            sleep = -1
            n = int(d / c)
            sleep = c * n - d
            while(sleep < 1):
                n += 1
                sleep = c * n - d
            
            if sleep < 1:
                print(-1)
            else:
                '''
                while(nokori > 0):
                    nokori -= sleep
                    res += c
                print(res)
                '''
                
                e = nokori % sleep
                f = int(nokori / sleep)
                if e == 0:
                    res += c * n * f
                else:
                    if c > d:
                        res += c * (f + 1)
                    if c < d:
                        res += c * n * (f + 1)
                print(res)