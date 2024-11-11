import sys

try:
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
except:
    pass

input = sys.stdin.readline

n = int(input())

st = []
ans = 0
curr = 1
for _ in range(2*n):
    op = list(input().strip().split())
    if op[0] == "add":
        st.append(op[1])
    else:
        if st:
            if st[-1] == curr: 
                st.pop()
            else:
                ans += 1
                st = []
    curr += 1

print(ans)
            
            


