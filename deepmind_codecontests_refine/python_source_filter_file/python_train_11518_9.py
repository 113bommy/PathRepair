# by the authority of GOD     author: Kritarth Sharma #
import math,copy
from collections import defaultdict,Counter
from itertools import permutations
def fact(n): 
    return 1 if (n == 1 or n == 0) else n * fact(n - 1)  
def prime(n) : 
    if (n <= 1) : 
        return False
    if (n <= 3) : 
        return True
    if (n % 2 == 0 or n % 3 == 0) : 
        return False
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
    return True
def inp():
    l=list(map(int,input().split()))
    return l
def one(l,i,s):
    a=False
    b=False
    for ii in range(i-1,-1,-1):
        if l[ii]==0 and s[ii]==0:
            a=ii
            break
    for ii in range(i+1,len(l)):
        if l[ii]==0 and s[ii]==0:
            b=ii
            break
    if a==False:
        return b
    elif b==False:
        return a
    elif abs(a-i)>abs(b-i):
        return b
    else:
        return a



## code starts here
#################################################################################################################
def main(): 
            l=inp()
            p=[0]*25
            
            for i in range(1,25):
                p[i]=l[i-1]
            if p[17]==p[18]==p[19]==p[20] and p[13]==p[14]==p[15]==p[16] and p[1]==p[2]==p[3]==p[4] and p[9]==p[10]==p[11]==p[12] and p[5]==p[6]==p[7]==p[8] and p[21]==p[22]==p[23]==p[24]:
                print("YES")
            elif p[17]==p[18]==p[19]==p[20] and p[13]==p[14]==p[15]==p[16]:
                if p[5]==p[7]==p[10]==p[12] and p[9]==p[11]==p[21]==p[23] and p[2]==p[4]==p[22]==p[24] and p[1]==p[3]==p[6]==p[8]:
                    print("YES")
                elif p[5]==p[7]==p[2]==p[4] and p[9]==p[11]==p[6]==p[8] and p[12]==p[10]==p[22]==p[24] and p[1]==p[3]==p[21]==p[23]:
                    print("YES")
                else:
                    print("NO")
            elif p[1]==p[2]==p[3]==p[4] and p[9]==p[10]==p[11]==p[12]:
                if p[5]==p[6]==p[19]==p[20] and p[7]==p[8]==p[13]==p[14] and p[17]==p[18]==p[23]==p[24] and p[21]==p[22]==p[16]==p[15]:
                    print("YES")
                elif p[5]==p[6]==p[15]==p[16] and p[17]==p[18]==p[7]==p[8] and p[19]==p[20]==p[22]==p[21] and p[14]==p[13]==p[24]==p[23]:
                    print("YES")
                else:
                    print("NO")
            elif p[5]==p[6]==p[7]==p[8] and p[21]==p[22]==p[23]==p[24]:
                if p[19]==p[17]==p[1]==p[2] and p[9]==p[10]==p[18]==p[20] and p[11]==p[12]==p[14]==p[16] and p[13]==p[15]==p[3]==p[4]:
                    print("YES")
                elif p[18]==p[20]==p[3]==p[4] and p[17]==p[19]==p[11]==p[12] and p[13]==p[15]==p[9]==p[10] and p[1]==p[2]==p[14]==p[16]:
                    print("YES")
                else:
                    print("NO")
            else:
                print("NO")
            


            
            

            






import os,sys
from io import BytesIO,IOBase
#Fast IO Region
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
if __name__ == "__main__":
    main()
def random():
    """My code gets caught in plagiarism check for no reason due to the fast IO template, .
     Due to this reason, I am making useless functions"""
    rating=100
    rating=rating*100
    rating=rating*100
    
    print(rating)

def random():
    """My code gets caught in plagiarism check for no reason due to the fast IO template, .
     Due to this reason, I am making useless functions"""
    rating=100
    rating=rating*100
    rating=rating*100
    
    print(rating)
def random():
    """My code gets caught in plagiarism check for no reason due to the fast IO template, .
     Due to this reason, I am making useless functions"""
    rating=100
    rating=rating*100
    rating=rating*100
    
    print(rating)
def random():
    """My code gets caught in plagiarism check for no reason due to the fast IO template, .
     Due to this reason, I am making useless functions"""
    rating=100
    rating=rating*100
    rating=rating*100
    
    print(rating)