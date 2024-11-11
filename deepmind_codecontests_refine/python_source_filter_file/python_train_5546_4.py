from sys import stdin, stdout

class SOLVE:
    def solve(self):
        R = stdin.readline
        #f = open('input.txt');R = f.readline
        W = stdout.write
        
        ans = []
        
        for i in range(int(R())):
            n = int(R())
            a = [int(x) for x in R().split()]
            a.sort(reverse = True)
            a = ['xtra'] + a
            
            pos = neg = 0
            for j in range(1, n+1):
                if a[j] < 0:
                    neg += 1
                else:
                    pos += 1
            
            POS  = {}
            for j in range(1, min(6, pos+1)):
                if j == 1:
                    POS[j] = a[j]
                else:
                    POS[j] = POS[j-1] * a[j]
                    
            NEG1 = {}
            for j in range(pos+1, min(pos+6, pos+neg+1)):
                if j == pos+1:
                    NEG1[j-pos] = a[j]
                else:
                    NEG1[j-pos] = NEG1[j-pos-1] * a[j]
            
            NEG2 = {}
            for j in range(n, n-min(5, neg), -1):
                if j == n:
                    NEG2[n-j+1] = a[j]
                else:
                    NEG2[n-j+1] = NEG2[n-j] * a[j]
                    
                    
                    
            mx = -10000000000
            for j in range(pos+1):
                if (j == 0) and (5 in NEG1):
                    mx = max(mx, NEG1[5])
                elif (j == 5) and (5 in POS):
                    mx = max(mx, POS[5])
                elif (j in POS) and ((5-j) in NEG1):
                    mx = max(mx, POS[j]*NEG1[5-j])
                    
                    
            for j in range(pos+1):
                if (j == 0) and (5 in NEG2):
                    mx = max(mx, NEG2[5])
                elif (j == 5) and (5 in POS):
                    mx = max(mx, POS[5])
                elif (j in POS) and ((5-j) in NEG2):
                    mx = max(mx, POS[j]*NEG2[5-j])
                    
            if neg >= 5:    
                for j in range(neg+1):
                    if (j == 0) and (5 in NEG2):
                        mx = max(mx, NEG2[5])
                    elif (j == 5) and (5 in NEG1):
                        mx = max(mx, NEG1[5])
                    elif (j in NEG1) and ((5-j) in NEG2):
                        mx = max(mx, NEG1[j]*NEG2[5-j])
                        
            ans.append(str(mx))
        
        W('\n'.join(ans))
        
def main():
    s = SOLVE()
    s.solve()
main()