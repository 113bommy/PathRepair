class Polygon(object):
    def is_nice(self):
        self.n = int(input())
        for i in range(self.n):
            self.m = int(input())
            if (self.m)%2==0:
                print('YES')
            else:
                print('NO')
cc = Polygon()
cc.is_nice()