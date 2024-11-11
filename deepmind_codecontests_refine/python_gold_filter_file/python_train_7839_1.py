#Fast I/O
import sys,os
import math
# To enable the file I/O i the below 2 lines are uncommented.
# read from in.txt if uncommented
if os.path.exists('in.txt'): sys.stdin=open('in.txt','r')
# will print on Console if file I/O is not activated
#if os.path.exists('out.txt'): sys.stdout=open('out.txt', 'w')
 
# inputs template
from io import BytesIO, IOBase
 
def ans(a,m):
    if m == 0 :
        return a
    a = list(a)
    if len(set(a)) == 1 :
        return a
    if (len(a)==1):
        return a
    if len(a)==2 :
        if a[0]=="0" and a[1]=="1" and m > 0:
            return ["1","1"]
        elif a[0]=="1" and a[1]=="0" and m > 0:
            return ["1","1"]
        else:
            return a
    x = []
    for i in range(len(a)) :
        j = i - 1
        k = i + 1
        if a[i] == "1":
            x.append(a[i])
        else:
            if j<0:
                if a[k]=="1":
                    x.append("1")
                else:
                    x.append("0")
            if k==len(a):
                if a[j]=="1":
                    x.append("1")
                else:
                    x.append("0")
            if j>=0 and k<len(a):
                if a[j]=="1" and a[k]=="0":
                    x.append("1")
                elif a[j]=="0" and a[k]=="1":
                    x.append("1")
                else:
                    x.append("0")
    x_new = a
    m-=1
    while(m!=0 and x!=x_new):
        x_new = x
        a = x
        x = []
        m-=1
        for i in range(len(a)) :
            j = i - 1
            k = i + 1
            if a[i] == "1":
                x.append(a[i])
            else:
                if j<0:
                    if a[k]=="1":
                        x.append("1")
                    else:
                        x.append("0")
                if k==len(a):

                    if a[j]=="1":
                        x.append("1")
                    else:
                        x.append("0")
                if j>=0 and k<len(a):
                    if a[j]=="1" and a[k]=="0":
                        x.append("1")
                    elif a[j]=="0" and a[k]=="1":
                        x.append("1")
                    else:
                        x.append("0")
    return x

def main():
    for _ in range(int(input())):
        n,m = MI()
        a = input()
        fin = ans(a,m)
        fin = "".join(fin)
        print(fin)
 
 
 
# Sample Inputs/Output 
 
# region fastio
 
BUFSIZE = 8192
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
#for array of integers
def MI():return (map(int,input().split()))
# endregion
#for fast output, always take string
def outP(var): sys.stdout.write(str(var)+'\n')  
# end of any user-defined functions
 
MOD=10**9+7
mod=998244353
 
# main functions for execution of the program.
 
if __name__ == '__main__':  
    #This doesn't works here but works wonders when submitted on CodeChef or CodeForces 
    main()
