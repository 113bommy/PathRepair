from sys import stdin, stdout
input = stdin.readline

def case():
    h, n = map(int, input().split())
    platforms = [int(i) for i in input().split()] + [0]
    i = 0
    pos = platforms[i]
    crystal_counter = 0
    while platforms[i] and i+1 < n:
        if platforms[i] - platforms[i+1] > 1:
            platforms[i] = platforms[i+1] + 1
            continue
        if platforms[i] - platforms[i+2] > 2:
            crystal_counter+=1
            platforms[i+1] = platforms[i+2] + 1
            i+=1
        elif platforms[i] - platforms[i+2] == 2:
            i+=2
    return crystal_counter
            
def main():
    ans = []
    q = int(input())
    for _ in range(q):
        ans.append(str(case()))
    stdout.write('\n'.join(ans))

if __name__ == '__main__':
    main()
