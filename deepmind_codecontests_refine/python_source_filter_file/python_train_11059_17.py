import sys
 
input = sys.stdin.readline
 
t = int(input())
 
for _ in range(t):
    s = input()
    a = [0] + [i + 1 for i in range(len(s)) if s[i] == 'R'] + [len(s) + 1]
    b = [a[i] - a[i - 1] for i in range(1, len(a))]
    print(max(b))
