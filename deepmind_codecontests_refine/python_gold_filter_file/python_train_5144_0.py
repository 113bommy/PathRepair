from sys import stdin,stdout
nmbr = lambda: int(stdin.readline())
lst = lambda: list(map(int, stdin.readline().split()))
for _ in range(1):#nmbr()):
    n,k=lst()
    a=[]
    for v in lst():
        if v<0:a+=[-v]
    a.sort(reverse=True)
    print(sum(a[:min(len(a),k)]))