class stack:
    def __init__(self):
        self.slist = []
        self.length = 0
    def push(self,element):
        self.slist += [element]
        self.length+=1
    def pop(self):
        if(self.length>0):
            self.length-=1
            c = self.slist[self.length]
            self.slist = self.slist[:self.length:]
            return c
        return -1
    def top(self):
        if(self.length>0):
            return self.slist[self.length-1]
        return -1


a = [i for i in input()]
a = a[::-1]
s = stack()
c = False
if(len(a)>=7):
    cont = 0
    while(cont!=7 and a!=[]):
        if(cont<6):
            if(a[0]=="0"):
                s.push("0")
                cont+=1
        else:
            if(a[0]):
                s.push("1")
                cont+=1
        a = a[1::]
    if(cont==7):
        c = True
    
if(c):
    print("yes")
else:
    print("no")
