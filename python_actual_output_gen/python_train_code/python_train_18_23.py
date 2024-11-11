class Solution:
    def checkPosible(self,n,S):
        Set = []
        for i in range(n):
            Set += list(map(int,input().split(' ')))
            
        if sum(set(Set))==Sm:
            return 'YES'
        else:
            return 'NO'
            

if __name__ == '__main__':
    n,m = list(map(int,input().split(' ')))
    Sm = sum([i for i in range(1,m+1)])
    S = Solution()
    print (S.checkPosible(n,Sm))
    
