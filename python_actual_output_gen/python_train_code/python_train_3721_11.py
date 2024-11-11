class Solution():
    def __init__(self,n,a):
        for i in range(n):
            a[i]=int(a[i])
        res=0
        for i in range(1,n):
            if a[i]!=a[0]:
                res=i
        les=0
        i=n-1
        while i>=0:
            if a[i]!=a[n-1]:
                les=i
            i-=1
        print(max(les,res))




if __name__ == '__main__':
    n=int(input())
    a=input().split()
    Solution(n,a)
