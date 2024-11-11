n = int(input())
birds_on_lines = list(map(int,input().split()))
m = int(input())
for shot in range(1,m+1):
    line,killed = map(int,input().split())
    if line>1:
        birds_on_lines[abs(line - 2)] += killed - 1
    if line<5:
        birds_on_lines[line] += birds_on_lines[line-1] - killed
    birds_on_lines[line-1] =0
for line in birds_on_lines:
    print(line)