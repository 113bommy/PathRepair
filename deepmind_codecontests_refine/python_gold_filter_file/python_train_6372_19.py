from sys import stdin,stdout

n,k = map(int, stdin.readline().split())
s = stdin.readline().strip()
letters = set(c for c in stdin.readline().split())

i,j = 0,0
count = 0

while j <= n:
    if j==n or s[j] not in letters:
        if i != j:
            count += (j-i)*(j-i+1)
        j+=1
        i = j
    else:
        j+=1

stdout.write("{}\n".format(count//2))
