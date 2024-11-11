class so_sanh(object):
    def __init__(self,p,t):
        self.p = p
        self.t = t
    def aaa(self):
        if(3*self.p/10<(self.p-self.p*self.t/250)):
            return (self.p-self.p*self.t/250)
        else:
            return (3*self.p*10)
a,b,c,d=map(int,input().split())
m=so_sanh(a,c)
v=so_sanh(b,d)
if(m.aaa()<v.aaa()):
    print("Vasya")
elif(m.aaa()==v.aaa()):
    print("Tie")
else:
    print("Misha")