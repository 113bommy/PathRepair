
def compute(n: int, s: str) -> int:
    if n == 1:
        return 0
    i = 0
    while i < n - 1 and s[i] != s[i + 1]:
        i += 1
    if i == n - 1:
        return 0
    z = 1
    o = 1
    if i > 0:
         if s[0] == '0':
             o += i
         else:
             z += i
    i += 2
    for j in range(i, n):
        if j % 2 == 0:
            if s[j] == '0':
                o += 1
            else:
                z += 1 
        else:
            if s[j] == '0':
                z += 1 
            else:
                o += 1
    return min(z, o)
             
    
if __name__ == '__main__':
    N = int(input())
    S = input()
    print(compute(N, S))
