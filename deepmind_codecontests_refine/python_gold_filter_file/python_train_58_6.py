import re
class Memory:
    def __init__(self,bytes):
        self.memory = [0 for x in range(bytes)]
        self.identifier = 1
    def out(self):
        print(self.memory)
    def alloc(self,bytes):
        avail = False
        for i in range(len(self.memory)-(bytes-1)):
            if max(self.memory[i:i+bytes])==0:
                print(self.identifier)
                for j in range(i,i+bytes):
                    self.memory[j]=self.identifier
                self.identifier+=1
                avail = True
            if avail:
                break
        if not avail:
            print("NULL")
    def erase(self,x):
        if x in self.memory and x!=0:
            for i in range(self.memory.count(x)):
                self.memory[self.memory.index(x)]=0
        else:
            print("ILLEGAL_ERASE_ARGUMENT")
    def defrag(self):
        zeroCount = self.memory.count(0)
        for i in range(zeroCount):
            self.memory.remove(0)
            self.memory.append(0)


t,m = map(int,input().split())
memory = Memory(m)
for i in range(t):
    operation = input()
    if operation.startswith("alloc"):
        aN = re.findall(r'\b\d+\b', operation)
        memory.alloc(int(aN[0]))
    elif operation.startswith("erase"):
        aE = re.findall(r'\b\d+\b', operation)
        memory.erase(int(aE[0]))
    else:
        memory.defrag()
