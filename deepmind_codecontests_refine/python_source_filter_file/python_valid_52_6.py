from sys import stdin, stdout
test = int(stdin.readline())
ans = []
for _ in range(test):
    n = int(stdin.readline())
    inp = list(map(int,stdin.readline().split()))
    inp.sort(reverse=True)
    cumu = [inp[0]]
    for i in range(1,len(inp)):
        cumu.append(inp[i]+cumu[-1])
    maxim = -1e9
    for i in range(len(inp)-1):
        maxim = max(maxim,cumu[i]/(i+1) + (cumu[-1]-cumu[i])/(len(inp)-i-1))
    ans.append(maxim)
for i in ans:
    stdout.write(str(i)+'\n')
