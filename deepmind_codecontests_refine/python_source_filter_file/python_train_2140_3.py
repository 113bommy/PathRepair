from sys import stdin, stdout
n, m = map(int, stdin.readline().split())
hcoordinate = list(map(int, stdin.readline().split()))
tcoordinate = list(map(int, stdin.readline().split()))
l = 0
r = max(abs(tcoordinate[-1] - hcoordinate[-1]), abs(tcoordinate[0] - hcoordinate[-1]))


while r > l + 1:
    t = (r + l) // 2
    i, j = 0, 0
    while i < n and j < m:
        if abs(hcoordinate[i] - tcoordinate[j]) <= t:
            i += 1
        else:
            j += 1
            
    if i == n:
        r = t
    else:
        l = t


stdout.write(str(r))