def PRINT(yy):
    a=yy//3600
    if a == 0:print('00:',end="")
    elif a >= 10:print(str(a)+':',end="")
    else:print('0'+str(a)+':',end="")
    yy%=3600
    a = yy//60
    if a == 0:print('00')
    elif a >= 10:print(str(a))
    else:print('0'+str(a))
class MyApp():
    
    def __init__(self,s,t):
        self.s = s
        self.t = t
    
    def build(self):
        S = self.s.split(':')
        T = self.t.split(':')
        S = (int(S[0])*3600)+(int(S[1])*60)
        T = (int(T[0])*3600)+(int(T[1])*60)
        self.yy = S-T
        #print(S,T,self.yy)
        
        if self.yy > 0:
            PRINT(self.yy)

        elif self.yy < 0:
            self.yy = 86400 - abs(self.yy)
            PRINT(self.yy)
        else:
            print('00:00')
root = MyApp(input(),input())
root.build()

