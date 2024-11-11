import sys
 
n = int(sys.stdin.readline())
 
for i in range(n):
    string = sys.stdin.readline()
    n, n1, n2 = string.split()
    
    n = int(n)
    n1 = int(n1)
    n2 = int(n2)
    aux = min(n - n1,n - n2)
    print(aux + 1 )