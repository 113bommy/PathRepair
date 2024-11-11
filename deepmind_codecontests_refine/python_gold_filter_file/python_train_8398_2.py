import sys
n = int(sys.stdin.readline().lstrip().rstrip())
w = list(map(int,sys.stdin.readline().lstrip().rstrip().split()))
word = sys.stdin.readline().lstrip().rstrip()
seat = []
for i in range(n):
    seat.append([w[i],i])
seat.sort()
visited = [False for i in range(n)]
stack = []
intro,extro = 0,0
for i in word:
    if i=='0':
        x = seat[intro]
        sys.stdout.write(str(x[1]+1)+' ')
        stack.append(x[1]+1)
        intro+=1
    else:
        sys.stdout.write(str(stack[-1])+' ')
        stack.pop()