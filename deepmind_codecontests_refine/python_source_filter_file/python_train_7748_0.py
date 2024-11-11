from sys import stdin, stdout

def main():
    n, k  = [int(x) for x in stdin.readline().rstrip().split()]
    

    table = [[0] * (n + 1) for _ in range(k + 1)]
    table[1] = [1] * (n + 1)

    MOD = int(1e9 + 7)
    for i in range(2, k + 1): 
        for j in range(1, n + 1):
            for k in range(j, n + 1, j):
                table[i][k] += table[i - 1][j]
                table[i][k] %= MOD

    print((sum(table[-1])) % MOD)
 

if __name__ == '__main__':
    main()
