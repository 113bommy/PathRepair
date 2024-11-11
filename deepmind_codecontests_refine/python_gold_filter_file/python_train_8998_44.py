import sys
input = sys.stdin.readline

n = input()
ans = [4,0,0,0]
if(len(n)<2):
    n = int(n)
else:
    n = int(n[-3:])
print(ans[n%4])