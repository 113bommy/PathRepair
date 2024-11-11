def Vitaly(s, n, m):
                res = 0
                for i in range(n):
                                j = 0
                                while j < 2*m:
                                                if 1 in s[i][j:j + m]:
                                                                res = res + 1
                                                j = j + m
                                                
                return res
n, m = input().split()
s = []
for i in range(int(n)):
                s1 = [int(n) for n in input().split()]
                s.append(s1)
print(Vitaly(s, int(n), int(m)))
                                                