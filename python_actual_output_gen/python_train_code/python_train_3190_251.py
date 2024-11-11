class win(object):
    def is_prize(self):
        n,m,k = map(int,input().strip().split())
        if k>=n or m>=n:
            print('Yes')
        else:
            print('No')
            
cc = win()
cc.is_prize()