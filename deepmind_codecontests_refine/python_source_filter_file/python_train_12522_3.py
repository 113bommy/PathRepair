import io
import os

#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def solve():
    n, m = map(int, input().split())
    
    a = input()
    b = input()
    
    best = 0
    #row = list(-i for i in range(len(a)+1))
    row = [0] * (n+1)
    for col in range(len(b)):
        #new_row = [-col-1]
        new_row = [0]
        for i in range(len(a)):
            if a[i] == b[col]:
                new_val = row[i] + 4 - 2
            else:
                new_val = row[i] - 2
            new_val = max(new_val, row[i] - 1)
            new_val = max(new_val, new_row[i] - 1)
            new_val = max(new_val, 0)
            best = max(best, new_val)
            new_row.append(new_val)
        row = new_row
    print(best)
    
t = 1

for _ in range(t):
    solve()
