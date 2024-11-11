from math import gcd
class predefine():
    def intt(self): return int(input())
    def strng(self): return input()
    def lst(self): return list(map(int,input().split()))

class letdo():
    def solve(self):
        pd = predefine()
        n = pd.intt()
        l=n-2
        while gcd(l,n-l)!=1:
            l-=1
        print(l,n-l,1)

    def solution(self):
        pd = predefine()
        c = pd.intt()
        while(c):
            self.solve()
            c-=1

    '''def solution(self):
        self.solve()'''

test = letdo()
test.solution()