from sys import stdin, exit
 
for _ in range(int(stdin.readline())):
    l = list(stdin.readline().split()[0])
    a = []
    n = len(l)
    for i in range(n):
        a.append(int(l[n-i-1]+i*'0'))
    r = [i for i in a if i!=0]
    print(len(r))
    print(' '.join(map(str,r)))
        
exit()